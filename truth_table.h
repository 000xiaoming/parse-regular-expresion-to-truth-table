#ifndef __truth_table_h__
#define __truth_table_h__

#define left_ope 40   //rank1
#define right_ope 41  //rank7
#define and_ope 38   //rank5
#define or_ope 124     //rank3
#define not_ope 33      //rank6
#define con_ope 62     //rank2
#define same_or_ope 36  //rank4

#define ascll_to_char 48
#define char_to_ascll 48
#include <math.h> // pow
#include <stdio.h> // std i/o
#include <stdbool.h> //按位
#include <stdlib.h> //calloc function
//优先级
enum {rank1, rank2, rank3, rank4, rank5, rank6, rank7};
//变元数量
int index_val = 0;
//命题总字符数
int all_char = 0;
//抓取变元位置
int *val_position ;

int truth_table_output(char *ex_string);
int calculate(char *ex_string);
#endif
