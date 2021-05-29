# Rubiks-Cube
## Description
The [Rubik’s Cube](https://en.wikipedia.org/wiki/Rubik%27s_Cube) is an infamous puzzle designed in 1974 by a Hungarian professor, known as Ernő Rubik. The puzzle consists of a large cube being split into a 3x3 orientation of smaller cubes, with each side being able to rotate 360 degrees. Each side is assigned a colour, and the cube is considered **`solved`** when each side is made up of just one colour.
<br>
Every time you rotate a side, it breaks the colours apart, scrambling the puzzle. Once the cube is fully scrambled the aim is to try and piece all the colours together until it is back in its solved form.<br><br>
There are various methods to solve Rubik's Cube but here we will make use of `CFOP Algorithm` to solve the cube in a very optimized manner.
<br><br>
Sounds <i>interesting</i>,right?
<br><br>
Let's dig deep into the various aspects involved in solving the cube
## Theory
- explain about how we take input- explain opencv code (Ayushi)
- then algos invlolved to solve the cube (Chamma)
- explain about CFOP Algo (Chamma)
## Usage
### Notations
Every rotation of the cube is represented by a unique `color code` lying between `0-11 (both inclusive)` which are mentioned below:
```cpp
          COLOR CODES
 -----------------------------------
 Color  |  Clockwise  | Anticlockwise
 ------ |-------------|-------------
 white  |     0       |     6
 red    |     1       |     7
 green  |     2       |     8
 blue   |     3       |     9
 orange |     4       |     10
 yellow |     5       |     11
```
For example, `color code 5` means that the `yellow face` needs to be rotated only `once`.
<br>
Similar logic can be applied for other codes as well.
### Giving Input (Ayushi)
- How to click images - should include reference i.e, white down blue right/left---to be confirmed
- how to name the images
- how to run the python file
- explain the output which we get after running the above command
### Solving the cube
- how to give array input obtained after running CubeInput.py file
- How to run the file gcc command
- explain the output - attach output example
### Demo Input
The repo contains a [demo](https://github.com/KKVANONYMOUS/Rubiks-Cube/tree/master/demo) directory with [images](https://github.com/KKVANONYMOUS/Rubiks-Cube/tree/master/demo/images) folder for sample input for the `CubeInput.py` program which will generate the corresponding face matrix, to be given as input to `CFOP.cpp` program.
Or else the user can directly give the face matrix present in [Sample_Input_For_CFOP.txt](https://github.com/KKVANONYMOUS/Rubiks-Cube/blob/master/demo/Sample_Input_For_CFOP.txt) file as input to `CFOP.cpp` file.
<br><br>
For more info regarding giving input to the program you can refer to [Giving Input](#giving-input-ayushi) section.
#### Shuffle function
This function gives additional option to shuffle the cube in order to test the code for different cases. Just give the cube rotation input in the form of numbers ranging from 0-11 as decribed in [Notations](#notations) and press 12 when you are done with the shuffiling.
## Team
- Kunal Kumar Verma - [@kkvanonymous](https://github.com/KKVANONYMOUS)
- Ayushi Gupta - [@Ayushi-Gupta7](https://github.com/Ayushi-Gupta7)
- Chamma Sarraf - [@codeit-dotcom](https://github.com/codeit-dotcom)
