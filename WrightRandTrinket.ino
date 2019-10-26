// Steven Wright OneLiners: http://thewhynot100.blogspot.com/2014/02/72-smart-steven-wright-one-liners.html
// Based on example code from https://github.com/MajicDesigns/MD_Parola
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <avr/pgmspace.h>
#include <Adafruit_DotStar.h> // turn off Trinket onboard DotStar LED

// 

const char string_1[] PROGMEM = "42.7 percent of all statistics are made up on the spot.";
const char string_2[] PROGMEM = "A conscience is what hurts when all your other parts feel so good.";
const char string_3[] PROGMEM = "A lot of people are afraid of heights. Not me, I'm afraid of widths.";
const char string_4[] PROGMEM = "All those who believe in psychokinesis raise my hand.";
const char string_5[] PROGMEM = "Boycott shampoo! Demand the REAL poo!";
const char string_6[] PROGMEM = "Change is inevitable... except from vending machines.";
const char string_7[] PROGMEM = "Cross country skiing is great if you live in a small country.";
const char string_8[] PROGMEM = "Dancing is a perpendicular expression of a horizontal desire.";
const char string_9[] PROGMEM = "Droughts are because god didn't pay his water bill.";
const char string_10[] PROGMEM = "Drugs may lead to nowhere, but at least it's the scenic route.";
const char string_11[] PROGMEM = "Eagles may soar, but weasels don't get sucked into jet engines.";
const char string_12[] PROGMEM = "Everyone has a photographic memory. Some just don't have film.";
const char string_13[] PROGMEM = "Experience is something you don't get until just after you need it.";
const char string_14[] PROGMEM = "For a while, I didn't have a car... I had a helicopter... no place to park it, so I just tied it to a lamp post and left it running...[slow glance upward]";
const char string_15[] PROGMEM = "For my birthday I got a humidifier and a de-humidifier. I put them in the same room and let them fight it out.";
const char string_16[] PROGMEM = "George is a radio announcer, and when he walks under a bridge, you can't hear him talk.";
const char string_17[] PROGMEM = "Half the people you know are below average.";
const char string_18[] PROGMEM = "Hard work pays off in the future. Laziness pays off now.";
const char string_19[] PROGMEM = "Hermits have no peer pressure.";
const char string_20[] PROGMEM = "How do you tell when you're out of invisible ink?";
const char string_21[] PROGMEM = "I almost had a psychic girlfriend but she left me before we met.";
const char string_22[] PROGMEM = "I bought some powdered water, but I don't know what to add to it.";
const char string_23[] PROGMEM = "I brought a mirror to Lovers' Lane. I told everybody I'm Narcissus.";
const char string_24[] PROGMEM = "I busted a mirror and got seven years bad luck, but my lawyer thinks he can get me five.";
const char string_25[] PROGMEM = "I didn't get a toy train like the other kids. I got a toy subway instead. You couldn't see anything, but every now and then you'd hear this rumbling noise go by.";
const char string_26[] PROGMEM = "I drive way too fast to worry about cholesterol.";
const char string_27[] PROGMEM = "I hate it when my foot falls asleep during the day because that means it's going to be up all night.";
const char string_28[] PROGMEM = "I have an answering machine in my car. It says, 'I'm home now. But leave a message and I'll call when I'm out.'";
const char string_29[] PROGMEM = "I have two very rare photographs. One is a picture of Houdini locking his keys in his car. The other is a rare photograph of Norman Rockwell beating up a child.";
const char string_30[] PROGMEM = "I installed a skylight in my apartment... The people who live above me are furious.";
const char string_31[] PROGMEM = "I intend to live forever... so far, so good.";
const char string_32[] PROGMEM = "I know the guy who writes all those bumper stickers. He hates New York.";
const char string_33[] PROGMEM = "I put my air conditioner in backward. It got cold outside. The weatherman on TV was confused. 'It was supposed to be hot today.'";
const char string_34[] PROGMEM = "I rented a lottery ticket. I won a million dollars. But I had to give it back.";
const char string_35[] PROGMEM = "I replaced the headlights in my car with strobe lights, so it looks like I'm the only one moving.";
const char string_36[] PROGMEM = "I saw a bank that said '24 Hour Banking,' but I don't have that much time.";
const char string_37[] PROGMEM = "I saw a close friend of mine the other day... He said, 'Stephen, why haven't you called me?' I said, 'I can't call everyone I want. My new phone has no five on it.' He said, 'How long have you had it?' I said, 'I don't know... my calendar has no sevens on it.'";
const char string_38[] PROGMEM = "I saw a sign: 'Rest Area 25 Miles'. That's pretty big. Some people must be really tired.";
const char string_39[] PROGMEM = "I saw a small bottle of cologne and asked if it was for sale. She said, 'It's free with purchase.' I asked her if anyone bought anything today.";
const char string_40[] PROGMEM = "I saw a subliminal advertising executive, but only for a second.";
const char string_41[] PROGMEM = "I spilled spot remover on my dog. Now he's gone.";
const char string_42[] PROGMEM = "I stayed in a really old hotel last night. They sent me a wake-up letter.";
const char string_43[] PROGMEM = "I still have my Christmas tree. I looked at it today. Sure enough, I couldn't see any forests.";
const char string_44[] PROGMEM = "I think God's going to come down and pull civilization over for speeding.";
const char string_45[] PROGMEM = "I think it's wrong that only one company makes the game Monopoly.";
const char string_46[] PROGMEM = "I took a course in speed reading. Then I got Reader's Digest on microfilm. By the time I got the machine set up, I was done.";
const char string_47[] PROGMEM = "I took a course in speed waiting. Now I can wait an hour in only ten minutes.";
const char string_48[] PROGMEM = "I took lessons in bicycle riding. But I could only afford half of them. Now I can ride a unicycle.";
const char string_49[] PROGMEM = "I used to work in a fire hydrant factory. You couldn't park anywhere near the place.";
const char string_50[] PROGMEM = "I was a peripheral visionary. I could see the future, but only way off to the side.";
const char string_51[] PROGMEM = "I was born by Caesarian section... but not so you'd notice. It's just that when I leave a house, I go out through the window.";
const char string_52[] PROGMEM = "Why do blonde women dye their roots dark?";
const char string_53[] PROGMEM = "I was going 70 miles an hour and got stopped by a cop who said, 'Do you know the speed limit is 55 miles per hour?' 'Yes, officer, but I wasn't going to be out that long...'";
const char string_54[] PROGMEM = "I was in the first submarine. Instead of a periscope, they had a kaleidoscope. 'We're surrounded.'";
const char string_55[] PROGMEM = "I was in the grocery store. I saw a sign that said 'pet supplies.' So I did.";
const char string_56[] PROGMEM = "I was in the grocery store. I saw a sign that said 'pet supplies'. So I did. Then I went outside and saw a sign that said 'compact cars'.";
const char string_57[] PROGMEM = "I was reading the dictionary. I thought it was a poem about everything.";
const char string_58[] PROGMEM = "I was sad because I had no shoes until I met a man who had no feet. So I said, 'Got any shoes you're not using?'";
const char string_59[] PROGMEM = "I wear my heart on my sleeve. I wear my liver on my pant leg.";
const char string_60[] PROGMEM = "I went over to the neighbor's and asked to borrow a cup of salt. 'What are you making?' 'A salt lick.'";
const char string_61[] PROGMEM = "I went to a fancy French restaurant called 'Deja Vu.' The headwaiter said, 'Don't I know you?'";
const char string_62[] PROGMEM = "I went to a garage sale. 'How much for the garage?' 'It's not for sale.'";
const char string_63[] PROGMEM = "I went to a general store. They wouldn't let me buy anything specifically.";
const char string_64[] PROGMEM = "I went to a haunted house, looked under the kitchen table, and found spirit gum.";
const char string_65[] PROGMEM = "I went to a restaurant that serves 'breakfast at any time.' So I ordered French Toast during the Renaissance.";
const char string_66[] PROGMEM = "I went to the museum where they had all the heads and arms from the statues that are in all the other museums.";
const char string_67[] PROGMEM = "I wrote a song, but I can't read music so I don't know what it is. Every once in a while I'll be listening to the radio and I say, 'I think I might have written that.'";
const char string_68[] PROGMEM = "I'd kill for a Nobel Peace Prize.";
const char string_69[] PROGMEM = "If at first you don't succeed, then skydiving definitely isn't for you.";
const char string_70[] PROGMEM = "If you are in a spaceship that is traveling at the speed of light, and you turn on the headlights, does anything happen?";
const char string_71[] PROGMEM = "If you must choose between two evils, pick the one you've never tried before.";
const char string_72[] PROGMEM = "If you were going to shoot a mime, would you use a silencer?";
const char string_73[] PROGMEM = "In my house there's this light switch that doesn't do anything. Every so often I would flick it on and off just to check. Yesterday, I got a call from a woman in Madagascar. She said, 'Cut it out.'";
const char string_74[] PROGMEM = "In school, every period ends with a bell. Every sentence ends with a period. Every crime ends with a sentence.";
const char string_75[] PROGMEM = "Is 'tired old cliche' one?";
const char string_76[] PROGMEM = "Last week I forgot how to ride a bicycle.";
const char string_77[] PROGMEM = "Monday is an awful way to spend 1/7th of your life.";
const char string_78[] PROGMEM = "My theory of evolution is that Darwin was adopted.";
const char string_79[] PROGMEM = "OK, so what's the speed of dark?";
const char string_80[] PROGMEM = "On the other hand, you have different fingers.";
const char string_81[] PROGMEM = "One time a cop pulled me over for running a stop sign. He said, 'Didn't you see the stop sign?' I said, 'Yeah, but I don't believe everything I read.'";
const char string_82[] PROGMEM = "Plan to be spontaneous tomorrow.";
const char string_83[] PROGMEM = "Right now I'm having amnesia and deja vu at the same time.";
const char string_84[] PROGMEM = "Someone sent me a postcard picture of the earth. On the back it said, 'Wish you were here.'";
const char string_85[] PROGMEM = "Someone told me half of all car accidents happen within a mile of your house. So I moved.";
const char string_86[] PROGMEM = "Sponges grow in the ocean. That just kills me. I wonder how much deeper the ocean would be if that didn't happen.";
const char string_87[] PROGMEM = "The problem with the gene pool is that there is no lifeguard.";
const char string_88[] PROGMEM = "The sign said 'eight items or less.' So I changed my name to Les.";
const char string_89[] PROGMEM = "There was a power outage at a department store yesterday. Twenty people were trapped on  escalators.";
const char string_90[] PROGMEM = "There's a fine line between fishing and standing on the shore looking like an idiot.";
const char string_91[] PROGMEM = "To steal ideas from one person is plagiarism; to steal from many is research.";
const char string_92[] PROGMEM = "What happens if you get scared half to death twice?";
const char string_93[] PROGMEM = "What's another word for Thesaurus?";
const char string_94[] PROGMEM = "When everything is coming your way, you're in the wrong lane.";
const char string_95[] PROGMEM = "When I turned two I was really anxious, because I'd doubled my age in a year. I thought, if this keeps up, by the time I'm six I'll be ninety.";
const char string_96[] PROGMEM = "When I was a little kid we had a sand box. It was a quicksand box. I was an only child... eventually.";
const char string_97[] PROGMEM = "Yesterday I parked my car in a tow-away zone...when I came back the entire area was missing.";
const char string_98[] PROGMEM = "Yesterday I told a chicken to cross the road. It said, 'what for?'";
const char string_99[] PROGMEM = "You can't have everything. Where would you put it?";
const char string_100[] PROGMEM = "You know how it is when you're reading a book and falling asleep, you're reading, reading... and all of a sudden you notice your eyes are closed? I'm like that all the time.";

// Set up a table to refer to the strings.

const char * const truisms[] PROGMEM = 
{ string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10,
  string_11, string_12, string_13, string_14, string_15, string_16, string_17, string_18, string_19, string_20,
  string_21, string_22, string_23, string_24, string_25, string_26, string_27, string_28, string_29, string_30,
  string_31, string_32, string_33, string_34, string_35, string_36, string_37, string_38, string_39, string_40,
  string_41, string_42, string_43, string_44, string_45, string_46, string_47, string_48, string_49, string_50,
  string_51, string_52, string_53, string_54, string_55, string_56, string_57, string_58, string_59, string_60,
  string_61, string_62, string_63, string_64, string_65, string_66, string_67, string_68, string_69, string_70, 
  string_71, string_72, string_73, string_74, string_75, string_76, string_77, string_78, string_79, string_80, 
  string_81, string_82, string_83, string_84, string_85, string_86, string_87, string_88, string_89, string_90, 
  string_91, string_92, string_93, string_94, string_95, string_96, string_97, string_98, string_99, string_100
};

int truismNumber[] ={ 83, 48, 18, 27, 85, 62, 13, 97, 51, 29, 45, 22, 37, 6, 2, 54, 19, 34, 74, 99, 91, 4, 81, 10,
                      35, 25, 3, 71, 44, 69, 42, 16, 77, 57, 39, 93, 88, 90, 52, 28, 24, 21, 49, 70, 7, 41, 53, 64, 11, 46, 89, 58, 14, 50,
                      43, 78, 72, 61, 56, 96, 12, 9, 17, 1, 55, 60, 80, 63, 59, 23, 87, 98, 47, 66, 31, 40, 5, 100, 94, 73, 76, 32, 20,
                      38, 65, 36, 33, 26, 84, 86, 75, 82, 79, 92, 95, 8, 68, 30, 15, 63
                    };

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8

//pins for old Arduino
//#define CLK_PIN   13
//#define DATA_PIN  11
//#define CS_PIN    10

//pins for Trinket M0  - works for software SPI, but not hardware.
#define CLK_PIN   2
#define DATA_PIN  0
#define CS_PIN    3

// HARDWARE SPI
// MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// SOFTWARE SPI
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Scrolling parameters
uint8_t scrollSpeed = 40;    // default frame delay value
textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;
//uint16_t scrollPause = 2000; // in milliseconds
uint16_t scrollPause = 0;

// Global message buffer
#define	BUF_SIZE	300
char curMessage[BUF_SIZE] = { "" };

Adafruit_DotStar strip = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

void setup()
{
  Serial.begin(9600);
  
  // turn off onboard dotstar
  strip.begin();
  strip.setPixelColor(0, 0, 0, 0); strip.show();

  // Initialize message subsystem
  P.begin();
  P.setIntensity(1);  //0 to 15
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
  
}

void loop()
{
      for (int i = 0; i <= 100; i++) {
        strcpy_P(curMessage, (char*)pgm_read_word(&(truisms[truismNumber[i+1]])));
     // strcpy_P(curMessage, (char*)pgm_read_word(&(truisms[i+1])));  // sequential array walk for debugging
        Serial.println(i + curMessage);
        while (!P.displayAnimate()) {};
        P.displayReset();
      }
}
