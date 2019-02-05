/*
 * Test if a point is inside a triangle.
 * Julian Saknussemm
 *
 * Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
 * the triangle.
 *
 * This is determined by satisfying the following rule:
 * A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
 * iff
 * P is on the same side of the line AB as C
 * P is on the same side of the line BC as A
 * and
 * P is on the same side of the line AC as B
 *
 * A special case exits for a vertical line (inf gradient) when testing the side of the line
 */
#define TRUE 1
#define FALSE 0
#define NUMOFSCANS 8
#include <stdio.h>
#include <assert.h>
void tests(void);
int test1(double px, double py, double m, double b, double lx, double ly);
int test2(double px, double py, double m, double b);
int tritest(double x0, double y0, double x1, double y1, double x2, double y2, double px, double py);

int main(int argc, char* argv[]) {
  tests();
  double x0,y0,x1,y1,x2,y2,px,py;
  int numOfScans = 0;
  // get input
  int flag;
  printf("Triangle Vertex A (x,y): "); numOfScans += scanf("%lf,%lf", &x0,&y0);
  printf("Triangle Vertex  B (x,y): "); numOfScans += scanf("%lf,%lf", &x1,&y1);
  printf("Triangle Vertex  C (x,y): "); numOfScans += scanf("%lf,%lf", &x2,&y2);
  printf("Test Point (x,y): "); numOfScans += scanf("%lf,%lf", &px,&py);
  // print error
  if(numOfScans != NUMOFSCANS) {
    printf("Not enough values were scanned.\n");
    flag = 1;
  } else {
    // print answer
    printf("Point (%.2lf,%.2lf) is ", px,py);
    if(tritest(x0,y0,x1,y1,x2,y2,px,py)) {
      printf("inside");
    } else {
      printf("outside");
    }
    printf(" the Triangle\n");
    // return 0
    flag = 0;
  }
  return flag;
}

void tests(void) {
  assert(tritest(0,0,5,5,10,0,4,3) == TRUE);
  assert(tritest(0,0,0,20,20,10,0,5) == FALSE);
  assert(tritest(10,0,5,10,0,0,4,3) == TRUE);
  assert(tritest(1,1,2,2,3,3,4,4) == TRUE);
  assert(tritest(200.32455,0,443.1243,124314.341321,4123.3214,132,500,1433) == TRUE);
  assert(tritest(500,0,500,1234,1000,600.24311,1100,0) == FALSE);
  printf("All tests passed! Good Job!\n");
}
 
int test2(double px, double py, double m, double b) {
  int flag;
  if(py < m * px + b) {
    flag = -1; // point is under line
  } else if (py == m * px + b) {
    flag =  0;
  } else {
    flag = 1; // over
  }
  return flag;
}
 
// two points lie on the same side of a line
int test1(double px, double py, double m, double b, double lx, double ly) {
  return (test2(px,py, m,b)==test2(lx,ly,m,b));
}

int tritest(double x0, double y0, double x1, double y1, double x2, double y2, double px, double py) {
  int line1, line2, line3;
  // line eqns
  double m01 = (y1-y0)/(x1-x0);
  // b: y - y1 = m( x - x1 ), x = 0
  double b01 = m01 * -x1 + y1;
  double m02, m12, b02, b12;
  m02 = (y2-y0)/(x2-x0);
  m12 = (y2-y1)/(x2-x1);
  b02 = m02 * -x2 + y2;
  b12 = m12 * -x2 + y2;
  // vertical line checks
  if( x1 == x0 ) {
     line1 = ((px <= x0) == (x2 <= x0));
  } else {
     line1 = test1(px, py, m01, b01, x2, y2);
  }
   
  if(x1 == x2) {
    line2 = ((px <= x2) == (x0 <= x2));
  } else {
    line2 = test1(px, py, m12, b12, x0, y0);
  }

  if(x2 == x0) {
    line3 = ((px <= x0 ) == (x1 <= x0));
  } else {
    line3 = test1(px, py, m02, b02, x1, y1);
  }
  return line1 && line2 && line3;
}