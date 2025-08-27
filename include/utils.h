#ifndef UTILS_H
#define UTILS_H

/* 
Performs a calculation to get a percentage (`percentage`) of `of`. 
*/
int getPercentageFrom(int percentage, int of);

/* 
Performs a calculation which returns what percentage is `percentage` 
compared to `of`.
*/
int getPercentageOf(int percentage, int of);

/* 
Checks if point `a` is inside the area of `b`

@param ax point `a` position in x axis
@param ay point `a` position in y axis
@param bx point `b` position in x axis
@param by point `b` position in y axis
@param bw point `b` width
@param bh point `b` height

@return `unsigned char` 0 if point a is not inside b, 1 if point a is inside b
*/
unsigned char isInside(int ax, int ay, int bx, int by, int bw, int bh);

#endif