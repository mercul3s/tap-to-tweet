import settings
import sys
import twitter

from BreakfastSerial import Arduino, Button, Led
from time import sleep

'''
Declare all our common variables and objects for use in our applicaton
'''
board = Arduino()

red_led       = Led(board, 13)
yellow_led    = Led(board, 12)
red_button    = Button(board, 7)
yellow_button = Button(board, 4)

counter = 0
# twitter = twitter.Api(consumer_key = settings.consumer_key,
#                       consumer_secret = settings.consumer_secret,
#                       access_token_key = settings.access_token,
#                       access_token_secret = settings.access_token_secret)

morse_code_dictionary = {
    "01"      : 'a',
    "1000"    : 'b',
    "1010"    : 'c',
    "100"     : 'd',
    "0"       : 'e',
    "0010"    : 'f',
    "110"     : 'g',
    "0000"    : 'h',
    "00"      : 'i',
    "0111"    : 'j',
    "101"     : 'k',
    "0100"    : 'l',
    "11"      : 'm',
    "10"      : 'n',
    "111"     : 'o',
    "0110"    : 'p',
    "1101"    : 'q',
    "010"     : 'r',
    "000"     : 's',
    "1"       : 't',
    "001"     : 'u',
    "0001"    : 'v',
    "011"     : 'w',
    "1001"    : 'x',
    "1011"    : 'y',
    "1100"    : 'z',
    "010101"  : "Full-Stop / period",
    # space
    "1000101" : " ",
    "01010"   : "End of message"   
}

def btn_down():
    global counter
    counter += 1
    red_led.on()
    print "button pressed %d times" % counter

def btn_up():
    red_led.off()
    print "button released"

def btn_held():
    red_led.on()
    print "button held for > 1 second"

red_button.down(btn_down)
red_button.up(btn_up)
red_button.hold(btn_held)

while True:
    continue