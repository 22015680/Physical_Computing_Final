# Weekly Blog --- Physical Computing Final Project 

Introduction
Concept
The theme of my project is the Ship of Theseus, which is a philosophical study of personal identity.
Today, with the development of artificial intelligence, people have infinite fantasies about the future. People will imagine whether they can achieve immortality if their mind can be uploaded to the network or machine. They will also wonder if this is the same person as the original one after uploading?

Housing
A cat. 3D print or cardboard handcraft to make a housing to contain Arduino and other kit.

Interaction Process
People approaching and voice input represent the upload process when the presence of light, sound and fluttering wings indicates a successful upload.

Possible Inputs
1.Ultrasonic Sensor: the closer the distance, the more upload progress.
2.Speech Recognizer/ Sound Detector: complete upload with special voice commands.

Possible Outputs
1.Neo-pixel Strip: to make cat halo and wings decorations.
2.LCD: to create a digital matrix similar to the visual effects of Matrix to build “cyber space”.
3.Magnetic Levitation Kit Push Type: after the successful upload, the halo of the cat floats, leaving a feeling of God's creation.
4.Servo Motor: drive the wings to flap.
5.Speaker: after successful upload, play the meow.

Ideation --- Week 5
Last week, a pcomp homework was assigned, which required us to present the project proposal in week 5.

Then, I use mind map to help me with ideation. Meanwhile, I do research on the keywords I write down and retrieve my memory. Fortunately, the inspiration pops up. My inspiration originates from the daily conversation topic. When we see cats can do nothing but eating or sleeping, and they can relax in the sun while we are working, we can't help but say: I want to be a cat in my next life. My inspiration also comes from Natsume Soseki's I Am a Cat, because its a book written in the view of cat. The discussion on the human cyberization in the Brief History of Humankind, where there is a discussion about whether mobile phone is also a kind of cyberprosthetics, also inspires me. Transcendence is also a movie about this question. Stray, a video game, where protagonist is a cat and there is also a scientist who uploaded his mind to robots. The game In Verbis Virtus gave me the inspiration of designing voice interaction.

When I think about the first version of the proposal, I consider more about the realization of the idea and less about the practical feasibility. Therefore, at the beginning, I want to use Magnetic Levitation. Later, I find that the push-up type is too large, and the upper-suction type need an extra installation containing magnet that can control the magnetic force on the cat's head. They are both complicated for me to do within a month when I am still working on another courses, so I give it up. I also think about making a cat device similar to an intelligent toy car. Although the survey results turn out that it is realizable, but because it is very common that almost every starters of mechanism would learn, I choose the current plan. I plan to print a cat model to contain Urduino Leronardo, perf and other components. Because I need to detect the distance, I plan to make the ultrasonic sensor a lacklace of the cat and insert the wires through the hole around the wings. When experiencers get closer, which is a process of uploading their mind, the LEDs will be brighter. When experiencers get close enough, they shout out “Hello World”, the sound detector will detect the sound and uploading process will be completed. The LCD will disaplay “hello world” the neo-pixel strip will light up and the wings will flap.


3D Modelling and Experiment --- Week 6
The goal of this week is to build a 3d cat in modelling software and test some components that I have never used before.
For the convenient and time limit, I decide to model my cat in Nomad, which is a sculpture software in the iPad. I’ve searched for some tips for creating 3d printing file. I learned to lower the poly count, key and split models for 3d printing, and trim a base for the model to stand. However, I "fight" with the 3d printer for almost a day and even adjust my model, but in the end it didn't work out. Hence, I intend to make a handmade cat shell out of cardboard. It seems to turn out pretty well now, the crafting reflects the loveliness of the painted cat compared to the loss of detail in the 3d print, and the wheels under the cat feet make it more mobile to take out and show off.

For the circuit, I separately test the ultrasonic sensor controlling neo-pixel stips and the speech recognizer controlling servo motor. When testing neo-pixel strips, I study the fast_led and Adafruit_NeoPixel library examples, and finally select fast_led's gradient effect. I use if statement to control the color changes, from blue and green gradient with 50 brightness greater than 30 cm, to less than 30 cm and larger than 5cm, the red and yellow gradient with 120 brightness, and finally to smaller than 5cm, the rainbow color gradient with 200 brightness. In my research, I encounter delay(); statement issue. It is not suitable for void loop, because it will delay the whole loop. Therefore, I try millis(); statement and it works, but then I realize I don't need a pause, so I delete them all. When soldering, I also encounter the problem of current direction of neo-pixel strips, which was originally soldered backwards, but was corrected by me later. I’ve also tried to play audio without using MP3 trigger or DFPlayer. I try to use encode audio and pcm library, and figure out how to connect the trigger with leonardo board. However, after testing ,there are two  problems prevent me from using the audio output — the sound of speaker is quite weird and the quality is low and the pcm library conflicts with the SoftwareSerial library, which is required by my neo-pixel strip. So far, I have two inputs and two outputs, so I have not tested LCD for the moment.



Housing and Making Schematic---Week 7
Fortunately, I’ve kept two discarded cardboard boxes that I can use to make a cat model. Firstly, I make one of two cardboard to be cat’s body. I use art knife to sculpture the feet. Because the cardboard box is too high for a cat, then I cut it off with scissors. The cat's head, ears, and wings are all copied from a design I drew at the end of the fourth week. I use scissors to poke four holes in the cardboard box bottom to assemble the wheels. I poke holes in each of the four caps with an electric solder iron and connect them with straws. A rubber band secure the ends to keep the wheels from slipping off.

I use TinkerCad to make a draft of my schematic and upload to fusion 360 to edit. Thanks to the testing, this step is very smooth.


Soldering and Assembling---Week 8
The presentation will be made this Friday, so the time is very tight. I solder according to the designed circuit diagram, and find that I only need to solder two straight PCB sockets on the perf that do not interfere with each other to connect the positive and negative poles of the power respectively. I glue the servo to the middle of the box with hot glue and pierce two holes in each wing. Then, I connect the wings to the servo with tin wire to move them. As there cannot be any block for the ultrasonic sensor, I solder its four pins with wire, and then glue it to the cat's neck with hot glue as a necklace.
For the final assembly part, code bugs, arduino board bugs, computer bugs, ide version bugs, soldering problems, and circuit problems, I have experienced all and solved one by one. 


Result

When people get closer, which is a process of uploading their mind, the neo-pixel strip will change the light mode from blue green gradient, to red yellow gradient, to rainbow gradient. When people shout out: “Hi, Cell”, wait the red light turn up, and say: “start” , wait the blue light turn up, the servo will drive the wings to flip. Likewise, when people shout out: “Hi, Cell”, wait the red light turn up, and say: “stop”, wait the blue light turn up, the servo and the wings will all stop.


Future Possibility

After I finish this project, I post it on my WeChat Moment and it is widely praised by my friends. Many postgraduate and undergraduate students want me to mass-produce it and they are willing to take them out shopping as AI pets. From that, I generate an idea for the future possibility of the project. I will try the LCD which has not been tested, and then try to use mp3 trigger or DFPlayer to trigger the audio, which will complete my unrealized idea before. In order to make the cat more intelligent, I will refer to the obstacle avoidance toy car, and make a cat shaped automatic driving toy car.
