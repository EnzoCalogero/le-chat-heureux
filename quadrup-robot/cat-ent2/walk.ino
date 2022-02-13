
void step1(void) {
int a[8] = { 0, 0, 0, -1, 0, 0, -1, 0 };
next_status(a);
delay(250);
int b[8] = { 0, 0, 1, -1, 0, 0, -1, 0};
next_status(b);
delay(250); 
int c[8] = { 0, 0, 1, -1, 0, 0, 0, 0};
next_status(c);
delay(250); 

  }


void step2(void) {
int a[8] = { 0, 0, 1, -1, 0, 0, 0, -1};
next_status(a);
delay(250);
int b[8] = { 0, 0, 1, 1, 0, 0, 0, -1};
next_status(b);
delay(250); 
int c[8] = { 0, 0, 1, 1, 0, 0, 0, 0};
next_status(c);
delay(250); 
}

void move(void) {
int a[8] = { 0, 0, 1, 1, 0, 0, 0, 0};
next_status(a);
delay(250);
int b[8] = { -1, -1, 0, 0, 0, 0, 0, 0};
next_status(b);
delay(250); 
}
 
