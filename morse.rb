require 'debugger'
require 'serialport'
require 'twitter'
load 'twitter_creds.rb'

# morse code dashes and dots stored as zeros and ones
# . = 0
# - = 1

@morse = {
	"01"      => 'a',
  "1000"    => 'b',
  "1010"    => 'c',
  "100"     => 'd',
  "0"       => 'e',
  "0010"    => 'f',
  "110"     => 'g',
  "0000"    => 'h',
  "00"      => 'i',
  "0111"    => 'j',
  "101"     => 'k',
  "0100"    => 'l',
  "11"      => 'm',
  "10"      => 'n',
  "111"     => 'o',
  "0110"    => 'p',
  "1101"    => 'q',
  "010"     => 'r',
  "000"     => 's',
  "1"       => 't',
  "001"     => 'u',
  "0001"    => 'v',
  "011"     => 'w',
  "1001"    => 'x',
  "1011"    => 'y',
  "1100"    => 'z',
  "010101"  => "Full-Stop / period",
              # space
  "1000101" => " ",
  "01010"   => "End of message"
}

@morse_code_letter = ""
@morse_tweet       = ""

# params for serial port

port_str  = "/dev/tty.usbserial-AD01TF8U"
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity    = SerialPort::NONE

@sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)  

# setup twitter API credentials (in secret!)
Twitter.configure do |config|
  config.consumer_key       = CONSUMER_KEY
  config.consumer_secret    = CONSUMER_SECRET
  config.oauth_token        = ACCESS_TOKEN
  config.oauth_token_secret = ACCESS_TOKEN_SECRET
end

def get_input
  while true do
    # get input from arduino. Input is defined as Serial.println("string" | number) 
    char = @sp.getc
    puts char
    # if our char input is zero or 1, then we append it to morse_code_letter
    # so, for example, if we want the code for 'a', we would enter a dot and dash
    # on our arduino, which would translate to a zero and one. @morse_code_letter
    # would then be '01'.
    # all input read from serial is a string, so evaluate it as such.

    # change the if elsif statements to case statements
    # add in full stop (wind sensor?) as instruction when to tweet
    
    if char == "0" or char == "1"
      @morse_code_letter << char.to_s
      puts @morse_code_letter
    # We're using a pipe to represent a break for a new character. If we encounter a
    # pipe, take whatever values we have in morse_code_letter, and look it up
    # in our morse code hash to pull the correct letter value.
    elsif char == "|"
      @morse_tweet << @morse[@morse_code_letter]
      @morse_code_letter = ""

    # We're using an asterisk for a break in a word. When we encounter this 
    # character, we lookup our letter, add it to morse tweet, and add a space
    # after it, then clear our letter for a new set of values.
    elsif char == "*"
      @morse_tweet << @morse[@morse_code_letter]
      @morse_tweet << " "
      @morse_code_letter = ""
    end
        
    if @morse_code_letter
      print @morse_code_letter
    end
  end
end

def parse_morse_code
  # while input is between 0 and 1
  # add input to morse_code_letter
  # else
  # lookup morse_code_letter in morse dictionary
  # append morse code letter to morse_tweet
  # clear morse_code_letter
  # start again at the top of the loop
  # check to make sure not more than 140 chars
end

# we have a begin/rescue block here due to 
def tweet(sentence)
  begin
      Twitter.update(sentence)
  rescue => e
      puts e
  end
end


get_input