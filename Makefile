CC := gcc
CFLAGS := -Wall -Werror -ggdb

OBJECTS := mat2.o mat4.o mat3.o vec3.o vec2.o vec4.o quat.o
HEADERS := $(OBJECTS:.o=.h)

all: $(OBJECTS) gl-matrix.a gl-matrix.h

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

gl-matrix.a: $(OBJECTS)
	ar -crs $@ $(OBJECTS)

gl-matrix.h: $(OBJECTS)
	cat $(HEADERS) > $@

clean:
	rm -rf *.o
	rm -f gl-matrix.h
	rm -f gl-matrix.a
