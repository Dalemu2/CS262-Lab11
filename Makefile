#Daniel Alemu G00884794
# CS 262, Lab Section 207
# # lab 11

CC= gcc
CFLAGS=-g -Wall
TARGET = lab11_dalemu2_207
# #all=   $(TARGET)
$(TARGET):  $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)

