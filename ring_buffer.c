#include<ring_buffer.h>





void rb_init(ring_buffer* rb, uint8_t* buf, uint8_t size) //you need to give this: the address of a ring_buffer struct, the address of the buffer within that struct, and the buffer size
{
	rb->buffer = buf;
	rb->size = size;
	rb->head = 0;
	rb->tail = 0;
}



void rb_put(ring_buffer* rb, uint8_t data) //takes pointer to struct and data to add to buffer
{
	rb->buffer[rb->head] = data; //accesses rb->buffer and sets the "headth" index equal to "data."
	rb-> head = (rb->head + 1) % rb->size; //increment head pointer
}


uint8_t rb_get(ring_buffer* rb)
{
	const uint8_t data = rb->buffer[rb->tail]; //creates a variable "data" and sets it equal to the value stored in the array rb->buffer with index rb->tail
	rb->tail++;
	rb->tail = (rb->tail + 1) % rb->size;
	return data;
}

uint8_t ring_buffer_peek(ring_buffer* rb)
{
	return(rb->buffer[rb->tail]);
}


bool rb_empty(ring_buffer* rb)
{
 return(rb->head == rb->tail); //returns true if head is equal to tail
}

bool rb_full(ring_buffer* rb)
{
	return(((rb->head + 1) % rb->size)) == rb->tail; //returns true if head is one behind tail
}

