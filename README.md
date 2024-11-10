# HackUmass 2024 Project - Nonchalant Nicholas
DevPost Submission: https://devpost.com/software/nonchalant-nicholas#updates
## Inspiration
The inspiration for this project was finding an easier way to locate spices in a spice cabinet and develop the evolution of the lazy Susan.

## What it does
Nicholas spins the spices around and dispenses the selected spice right out to you. The spice is selected via user input on a webpage.

## How we built it
The main hardware used was a stepper motor to spin the whole spice rack and a micro servo to push the arm which pushes the spice out. A client-facing UI allows users to pick a spice, and that data is sent to a node.js webserver, which then relays the data to the Arduino, which then controls the required hardware components to dispense the spice.

## Challenges we ran into
The main challenge for the hardware was designing the project's main components so that wires wouldn't get tangled while it was spinning around. The main challenge for the software was trying to relay the data from the webserver to the Arduino.

## Accomplishments that we're proud of
Hardware: designing/3D printing our gear and rack, finding a design so that wires are not in the way

## What we learned
Hardware: CAD, 3D printing, Arduino hardware (stepper motor, servo) Software: Node.js, HTML, Arduino code

## What's next for Nonchalant Nicholas
To continue this project, we would add voice activation, seasoning presets, and a manual operation mode. Additionally, we could expand the project's use to dispense other items like snacks, medicine, and drinks.

## Built with
- JavaScript
- NodeJS
- HTML
- Arduino
- TinkerCAD
- 3D Printing
