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
- ### (kunal)
   - When we pass the images of all the faces to `CubeInput.py`, it reads all the images one by one and stores the image data in the form of numpy array. To crop the unnecessary part of image, we have used `selectROI()` function. 
   - The croped image is then resized and pass to `face_color()` function where the different color blocks are masked out using their hsv values and `inRange()` function of opencv. This function returns a black-white image of each block where the particular color is white and rest is all black.
   - This image is passed to `mask()` function where we have find contours and then iterated over each contour and rejected small contours on the basis of area.We have initiliased a 2-d zero array in which we store the color states of each face. Using some maths and using centres of each block ,we have filled the 2-d array.
   - The blocks are given color according to following manner:
        - red:1
        - white:0
        - green:2
        - blue:3
        - orange:4
        - yellow:5
- ### Structures to Store the cube state
   - **arr** is a 2D vector which consists of all 6 colours and its index represents its neighbours. i.e- in arr[i][j] i denotes the colour code and j (0->color         code , 1->color code of upper block , 2-> left block , 3-> right block,4->bottom block , 5->yellow block) represent the color code of its neighbors.

   - **matrixes[6][9]** is a vector of struct faceMatrix consisting of two vectors v1 and v2 where v1 stores its current position of that block and v2 stores its        current position according to the centre.(i.e matrixes[1][1] looks for current position of 2 sided red-yellow block and v2 represent in which center red          color is faced).


- ### Algorithms involved in solving the cube
 - **Making White Cross** :- For making white cross we made a function `makeWhiteCross()`.There are 4!=24 (solving in any sequence of red , green , blue and            orange) ways to make white cross. We look for all the  possibilities. We first take a maximum of 30 steps and look for the minimum number of steps needed          and then apply it to make the white cross.
    
 - **F2L** :- After making white cross we make the first two layer (i.e- middle layer of red, green , blue and green and all four white corner pieces) using           the `implementF2L()` function based on the [F2L Algo](https://ruwix.com/the-rubiks-cube/advanced-cfop-fridrich/first-two-layers-f2l/).Here we have have           taken maximum steps as 100 and try all possibilities to reduce maximum steps by taking into account all the possible cases.
  
 - **Making Yellow Cross** :- First we check if the yellow cross is already made or not by using the `checkYellowCross()` function. If it's not, we call the           `createYellowCross()` function to make the  yellow cross by looking at all possible cases.

 - **OLL** :- When the first two layers (F2L) are solved we need to orient the last layer (OLL) so the upper face of the Rubik's Cube is all yellow. We don't care      if the side colors   don't  match, we are going to permute the last layer (PLL) in the next step. The function `oll()` implements the above algo by first          counting the number of yellow corners in the current cube state and then applying the corresponding algo for orienting the layer.

  - **PLL** :- In this final step we make use of the `setCorners` function to set the corners of the last layer and then call `setEdges` to finally set the edges.

Hurray our cube is solved!




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
- Click the images of all the faces following the pattern specified:
     Keep the face with red centre towards you, face with white centre at bottom , face with green centre at your right and so on
- Name all  the images in the format- 1.jpeg,2.jpeg and so on .
- Run the `CubeInput.py` file using the command "python3 CubeInput.py" from the terminal
- This python file will return the states of all the faces as shown in  [Sample_Input_For_CFOP.txt](https://github.com/KKVANONYMOUS/Rubiks-Cube/blob/master/demo/Sample_Input_For_CFOP.txt).Copy paste the content of this file and give this as an input to `CFOF.cpp` file.
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
