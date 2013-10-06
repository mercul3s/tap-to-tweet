require 'debugger'
require 'serialport'
require 'twitter'
load 'twitter_creds.rb'

# morse code dashes and dots stored as zeros and ones
# . = 0
# - = 1

morse = {
	01 => 'a',
    1000 => 'b',
    1010 => 'c',
    100 => 'd',
    0 => 'e',
    0010 => 'f',
    110 => 'g',
    0000 => 'h',
    00 => 'i',
    0111 => 'j',
    101 => 'k',
    0100 => 'l',
    11 => 'm',
    10 => 'n',
    111 => 'o',
    0110 => 'p',
    1101 => 'q',
    010 => 'r',
    000 => 's',
    1 => 't',
    001 => 'u',
    0001 => 'v',
    011 => 'w',
    1001 => 'x',
    1011 => 'y',
    1100 => 'z',
    010101 => "Full-Stop / period",
    1000101 => "Break / space",
    01010 => "End of message"
}

morse_code_letter = ""
morse_tweet       = ""

# params for serial port

port_str  = "/dev/tty.usbserial-AD01TF8U"
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity    = SerialPort::NONE

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)  

# setup twitter API credentials (in secret!)
Twitter.configure do |config|
    config.consumer_key       = CONSUMER_KEY
    config.consumer_secret    = CONSUMER_SECRET
    config.oauth_token        = ACCESS_TOKEN
    config.oauth_token_secret = ACCESS_TOKEN_SECRET
end

# check input from arduino
#
# 
def parse_morse_code
    # while input is between 0 and 1
    # add input to morse_code_letter
    # else
    # lookup morse_code_letter in morse dictionary
    # append morse code letter to morse_tweet
    # clear morse_code_letter
    # start again at the top of the loop
end

def tweet
    begin
        Twitter.update("Test")
    rescue => e
        puts e
    end
end
