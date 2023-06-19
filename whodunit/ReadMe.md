# Instructions

##### copy.c is a program whose sole purpose is to make a copy of a BMP.

## - Firstly Test `Compile copy.c into a program called copy using make.`

### `make copy`. Then execute a command like below.
### `./copy smiley.bmp copy.bmp`

#### this command copies the smiley.bmp file to the copy.bmp file.

#### If you then execute ls -l you should see that the smiley.bmp and copy.bmp files are indeed the same size. Let's check again that they are actually the same! Execute the following.

### `diff smiley.bmp copy.bmp` If that command tells you nothing, the files are indeed the same.


## - After That Create Whodunit and Execute Program
##### Finally, let's write a few lines of code to see how we can change the images. First, let's create the program called Whodunit that we want to write for this lab. Looks like "copy.c" is a great place to start, so let's go ahead and copy this file using the "cp" command in the terminal:

## `cp copy.c whodunit.c`

###### nstead of reading the RGBTRIPLE of the source file, let's write our own. Go and delete line 75 and the associated comment. Can you think of a way how to identify a purple pixel instead of what you just deleted? Let's replace each pixel in the original source with a purple pixel. Apparently, the hexadecimal color code for purple is 800080. When you think you got the event, compile the whodunit and run the command.

## `./whodunit clue.bmp verdict.bmp`
##### and hopefully double click on the image where you will see a purple wall!


###### Now, instead of ignoring the pixels in the source file, let's do something with them. To make a copy of the lines you deleted in the last example, go back to "copy.c" and paste them back where they belong in "whodunit.c". Maybe, to help Mr. Boddy, we could try swapping the pixels at some point between reading from source and writing to destination?

###### What if we just wanted to turn all the white pixels black, thinking that higher contrast could provide better readability? Or what if we wanted to turn all that red "noise" in the image to white? Or what if we wanted to better simulate that red piece of plastic idea and give everything a reddish shade? Maybe we can first use some conditional logic to check the different properties of the triple and then decide what to do with it based on the binary expression that will return.

###### This is your last challenge for now - you must make it for Mr. Boddy! If successful, after recompiling your code

### `./whodunit clue.bmp verdict.bmp`

###### Then you must uncover the answer to this mystery!