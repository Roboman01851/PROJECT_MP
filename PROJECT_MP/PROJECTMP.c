#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "alt_types.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "altera_avalon_pio_regs.h"
#include "COLOR_08.h"
#include "letters.h"



void Delay_Loading () {int d = 0; for (d = 0; d <  5000000; d++);}
void Delay_Long    () {int d = 0; for (d = 0; d <   500000; d++);}
void Delay_Medium  () {int d = 0; for (d = 0; d <   150000; d++);}
void Delay_Short   () {int d = 0; for (d = 0; d <     5000; d++);}
void Delay_Pulse   () {int d = 0; for (d = 0; d <        1; d++);}


void draw(int dd[24][16], int color, int x_offset, int y_offset)
{
alt_up_pixel_buffer_dma_dev* hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

int vertical, horizontal;

for (vertical=0; vertical<24; vertical++)
{
for (horizontal=0; horizontal<16; horizontal++)
{
if (dd[vertical][horizontal] > 0)
{
alt_up_pixel_buffer_dma_draw (hPB, color, horizontal+x_offset*16, vertical+y_offset*24);
}
}
}
}

void draw1(int bb[12][8], int color, int x_offset, int y_offset)
{
alt_up_pixel_buffer_dma_dev* hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

int vert;
int hori;

for (vert=0; vert<12; vert++)
{
for (hori=0; hori<8; hori++)
{
if (bb[vert][hori] == 1 )
{
alt_up_pixel_buffer_dma_draw (hPB, color, hori+x_offset*8, vert+y_offset*12);
}
}
}
}

int main ()
{

int x=0;
int y=0;
int z;
int square[24][16]=    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};//images/square.png//square.png
	int white[24][16]= {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					  , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};//images/square.png//square.png


	int dig_col[12][8]={{0,0,0,0,0,0,0,0}
					   ,{0,0,0,0,0,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,0,0,0,0,0}
					   ,{0,0,0,0,0,0,0,0}
					   ,{0,0,0,0,0,0,0,0}
					   ,{0,0,0,0,0,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,0,0,0,0,0}
					   ,{0,0,0,0,0,0,0,0}};

	int dig_zero[12][8]={{0,0,0,0,0,0,0,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
						,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,0,0,0,0,0,0,0}};

	int dig_one[12][8]={{0,0,0,0,0,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,1,1,0,0,0}
					   ,{0,0,0,0,0,0,0,0}};

	int dig_two[12][8]={{0,0,0,0,0,0,0,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,0,0,0,0,1,1,0}
					   ,{0,0,0,0,0,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,0,0,0,0,0}
					   ,{0,1,1,0,0,0,0,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,0,0,0,0,0,0,0}};

	int dig_three[12][8]={{0,0,0,0,0,0,0,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,0,0,0,0,0,0,0}};

	int dig_four[12][8]={{0,0,0,0,0,0,0,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
						,{0,1,1,1,1,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,0,0,0,0,0,0,0}};

	int dig_five[12][8]={{0,0,0,0,0,0,0,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,0,0,0,0,0}
					    ,{0,1,1,0,0,0,0,0}
					    ,{0,1,1,1,1,1,1,0}
						,{0,1,1,1,1,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,0,0,0,0,0,0,0}};

	int dig_six[12][8]={{0,0,0,0,0,0,0,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,0,0,0,0,0}
					   ,{0,1,1,0,0,0,0,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,0,0,1,1,0}
					   ,{0,1,1,0,0,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,1,1,1,1,1,1,0}
					   ,{0,0,0,0,0,0,0,0}};

	int dig_seven[12][8]={{0,0,0,0,0,0,0,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
						 ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,1,1,0}
					     ,{0,0,0,0,0,0,0,0}};

	int dig_eight[12][8]={{0,0,0,0,0,0,0,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,0,0,1,1,0}
					     ,{0,1,1,0,0,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,0,0,1,1,0}
					     ,{0,1,1,0,0,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,1,1,1,1,1,1,0}
					     ,{0,0,0,0,0,0,0,0}};

	int dig_nine[12][8]={{0,0,0,0,0,0,0,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,0,0,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
						,{0,1,1,1,1,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,0,0,0,0,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,1,1,1,1,1,1,0}
					    ,{0,0,0,0,0,0,0,0}};

	int dig_blank[12][8]={{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					 	 ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}
					     ,{1,1,1,1,1,1,1,1}};

alt_up_pixel_buffer_dma_dev* hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

    if (hPB == NULL)
    {
printf ("No VGA system in present\n");
while (1);
    }
    else
    {
alt_up_pixel_buffer_dma_clear_screen (hPB, 0);
alt_up_pixel_buffer_dma_clear_screen (hPB, 1);
    }

Delay_Long ();
srand (IORD_ALTERA_AVALON_PIO_DATA (SWITCH_BASE));
draw(S, COLOR08_BLUE, 0, 0);
draw(C, COLOR08_BLUE, 1, 0);
draw(O, COLOR08_BLUE, 2, 0);
draw(R, COLOR08_BLUE, 3, 0);
draw(E, COLOR08_BLUE, 4, 0);
draw(zero, COLOR08_WHITE, 5, 0);//x000
draw(zero, COLOR08_WHITE, 6, 0);//0x00
draw(zero, COLOR08_WHITE, 7, 0);//00x0
draw(zero, COLOR08_WHITE, 8, 0);//000x
draw(M, COLOR08_GOLD, 8, 1);
draw(P, COLOR08_GOLD, 9, 1);
draw(X, COLOR08_GOLD, 0, 1);
draw(zero, COLOR08_GRAY, 1, 1);
draw(zero, COLOR08_GRAY, 2, 1);
draw(Y, COLOR08_GOLD, 17, 1);
draw(zero, COLOR08_GRAY, 18, 1);
draw(zero, COLOR08_GRAY, 19, 1);
draw(L, COLOR08_RED, 13, 0);
draw(O, COLOR08_RED, 14, 0);
draw(A, COLOR08_RED, 15, 0);
draw(D, COLOR08_RED, 16, 0);
draw(I, COLOR08_RED, 17, 0);
draw(N, COLOR08_RED, 18, 0);
draw(G, COLOR08_RED, 19, 0);
		Delay_Loading ();
		IOWR_ALTERA_AVALON_PIO_DATA (DIGITAL_CLOCK_RESET_BASE, 1);
		IOWR_ALTERA_AVALON_PIO_DATA (DIGITAL_CLOCK_RESET_BASE, 0);
		draw(L, COLOR08_BLACK, 13, 0);
		draw(O, COLOR08_BLACK, 14, 0);
		draw(A, COLOR08_BLACK, 15, 0);
		draw(D, COLOR08_BLACK, 16, 0);
		draw(I, COLOR08_BLACK, 17, 0);
		draw(N, COLOR08_BLACK, 18, 0);
		draw(G, COLOR08_BLACK, 19, 0);



	draw1(dig_zero, COLOR08_RED, 29, 0);
	draw1(dig_zero, COLOR08_RED, 30, 0);
	draw1(dig_col, COLOR08_RED, 31, 0);
	draw1(dig_zero, COLOR08_RED, 32, 0);
	draw1(dig_zero, COLOR08_RED, 33, 0);
	draw1(dig_col, COLOR08_RED, 34, 0);
	draw1(dig_zero, COLOR08_RED, 35, 0);
	draw1(dig_zero, COLOR08_RED, 36, 0);
	draw1(dig_col, COLOR08_RED, 37, 0);
	draw1(dig_zero, COLOR08_RED, 38, 0);
	draw1(dig_zero, COLOR08_RED, 39, 0);
	IOWR_ALTERA_AVALON_PIO_DATA (DIGITAL_CLOCK_RESET_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA (DIGITAL_CLOCK_RESET_BASE, 0);
int nn;
int gameboard [8][20]={
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
};
int k = 5;
for (y=2; y<10; y++)
{
for (x=0; x<20; x++)
{
nn = rand()%k;
gameboard [y-2][x] =nn;
if (nn == 0)
{
	draw(zero, COLOR08_CYAN, x, y);
}
if (nn == 1)
{
	draw(one, COLOR08_GREEN , x, y);
}
if (nn == 2)
{
	draw(two, COLOR08_MAGENTA , x, y);
}
if (nn == 3)
{
	draw(three, COLOR08_PURPLE, x, y);
}
if (nn == 4)
{
	draw(four, COLOR08_GOLD, x, y);
}
if (nn == 5)
{
	draw(five, COLOR08_ORANGE, x, y);
}
if (nn == 6)
{
	draw(six, COLOR08_ROYALBLUE, x, y);
}
if (nn == 7)
{
	draw(seven, COLOR08_CRIMSON, x, y);
}
if (nn == 8)
{
	draw(eight, COLOR08_BLUE, x, y);
}
if (nn == 9)
{
	draw(nine, COLOR08_INDIGO, x, y);
}

}

}
int sec=0;
int min=0;
int hour=0;
int day=0;

int sec_a=0;
int sec_b=0;

int min_a=0;
int min_b=0;

int hour_a=0;
int hour_b=0;

int day_a=0;
int day_b=0;

int ct=0;
int q=1000000;
int f;
int t,w,r;
int button;
int clk=0;
int pause=0;
int key1;

int time=600;//amount of seconds till game over
/*
while(1)
{


	printf("%u \n",IORD_ALTERA_AVALON_PIO_DATA(DIGITAL_CLOCK_BASE));
}
*/
//right

for(f=0;f<100000;f++)
{
q=ct;
	for(x=0;x<18;)
{
	for(y=0;y<8;)
	{
		printf("clk: %i \n",clk);
		if(clk==time)
		{
			draw(white, COLOR08_BLACK, 11, 0);
			draw(G, COLOR08_RED, 11, 0);
			draw(white, COLOR08_BLACK, 12, 0);
			draw(A, COLOR08_RED, 12, 0);
			draw(white, COLOR08_BLACK, 13, 0);
			draw(M, COLOR08_RED, 13, 0);
			draw(white, COLOR08_BLACK, 14, 0);
			draw(E, COLOR08_RED, 14, 0);

			draw(white, COLOR08_BLACK, 15, 0);

			draw(white, COLOR08_BLACK, 16, 0);
			draw(O, COLOR08_RED, 16, 0);
			draw(white, COLOR08_BLACK, 17, 0);
			draw(V, COLOR08_RED, 17, 0);
			draw(white, COLOR08_BLACK, 18, 0);
			draw(E, COLOR08_RED, 18, 0);
			draw(white, COLOR08_BLACK, 19, 0);
			draw(R, COLOR08_RED, 19, 0);
			clk=time+1;
		}


		if(clk < time)
		{
		key1=IORD_ALTERA_AVALON_PIO_DATA(KEY1_BASE);

		if(key1==0)
		{
			pause++;
			Delay_Short();
		}

		if(pause%2==0)
		{
			IOWR_ALTERA_AVALON_PIO_DATA (DIGITAL_CLOCK_PAUSE_BASE, 1);
			//printf("not paused \n");

		}
		if(pause%2==1)
		{
			IOWR_ALTERA_AVALON_PIO_DATA (DIGITAL_CLOCK_PAUSE_BASE, 0);
			//printf("paused \n");
		}

		/*
		printf("pause: %i , key1: %i , number: %i \n", pause, key1 , pause%2);
		*/

		/*
		if(key1==0)
		{
			printf("pressed \n");
		}
		if(key1==1)
		{
			printf("not pressed \n");
		}
		*/

		if(y==0)//top
		{
		draw(square, COLOR08_RED, x,y+2);
		}

		if(y==7)//bottom
		{
		draw(square, COLOR08_RED, x,y+2);
		}

		if(x==0)//left
		{
		draw(square, COLOR08_RED, x,y+2);
		}

		if(x==19)//right
		{
		draw(square, COLOR08_RED, x,y+2);
		}


		if(x>0 && x<19 )//middle
		{
			if(y>0 && y<7)
			{
				draw(square, COLOR08_WHITE, x,y+2);
			}
		}
		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 0);
		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
		Delay_Pulse();
		button=IORD_ALTERA_AVALON_PIO_DATA(KEY_UDLRM_ENCODER_BASE);

		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 0);

		if(button==0 || button==1 || button==2 || button==3 || button==4 || button==5 || button==6)
		{
			clk = IORD_ALTERA_AVALON_PIO_DATA(DIGITAL_CLOCK_BASE);

			sec = clk%60;
			min = (clk/60)%60;
			hour = ((clk/60)/60)%24;
			day =  (((clk/60)/60)/24)%100;
			sec_a = sec/10;
			sec_b = sec%10;
			min_a = min/10;
			min_b = min%10;
			hour_a = hour/10;
			hour_b = hour%10;
			day_a = day/10;
			day_b = day%10;
			/*
			printf("%i:",day);
			printf("%i:",hour);
			printf("%i:",min);
			printf("%i\n",sec);
	*/
			if(sec_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_zero, COLOR08_RED, 39, 0);
			}
			if(sec_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_one, COLOR08_RED, 39, 0);
			}
			if(sec_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_two, COLOR08_RED, 39, 0);
			}
			if(sec_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_three, COLOR08_RED, 39, 0);
			}
			if(sec_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_four, COLOR08_RED, 39, 0);
			}
			if(sec_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_five, COLOR08_RED, 39, 0);
			}
			if(sec_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_six, COLOR08_RED, 39, 0);
			}
			if(sec_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_seven, COLOR08_RED, 39, 0);
			}
			if(sec_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_eight, COLOR08_RED, 39, 0);
			}
			if(sec_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_nine, COLOR08_RED, 39, 0);
			}




			if(sec_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_zero, COLOR08_RED, 38, 0);
			}
			if(sec_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_one, COLOR08_RED, 38, 0);
			}
			if(sec_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_two, COLOR08_RED, 38, 0);
			}
			if(sec_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_three, COLOR08_RED, 38, 0);
			}
			if(sec_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_four, COLOR08_RED, 38, 0);
			}
			if(sec_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_five, COLOR08_RED, 38, 0);
			}
			if(sec_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_six, COLOR08_RED, 38, 0);
			}
			if(sec_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_seven, COLOR08_RED, 38, 0);
			}
			if(sec_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_eight, COLOR08_RED, 38, 0);
			}
			if(sec_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_nine, COLOR08_RED, 38, 0);
			}


			if(min_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_zero, COLOR08_RED, 36, 0);
			}
			if(min_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_one, COLOR08_RED, 36, 0);
			}
			if(min_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_two, COLOR08_RED, 36, 0);
			}
			if(min_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_three, COLOR08_RED, 36, 0);
			}
			if(min_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_four, COLOR08_RED, 36, 0);
			}
			if(min_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_five, COLOR08_RED, 36, 0);
			}
			if(min_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_six, COLOR08_RED, 36, 0);
			}
			if(min_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_seven, COLOR08_RED, 36, 0);
			}
			if(min_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_eight, COLOR08_RED, 36, 0);
			}
			if(min_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_nine, COLOR08_RED, 36, 0);
			}




			if(min_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_zero, COLOR08_RED, 35, 0);
			}
			if(min_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_one, COLOR08_RED, 35, 0);
			}
			if(min_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_two, COLOR08_RED, 35, 0);
			}
			if(min_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_three, COLOR08_RED, 35, 0);
			}
			if(min_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_four, COLOR08_RED, 35, 0);
			}
			if(min_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_five, COLOR08_RED, 35, 0);
			}
			if(min_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_six, COLOR08_RED, 35, 0);
			}
			if(min_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_seven, COLOR08_RED, 35, 0);
			}
			if(min_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_eight, COLOR08_RED, 35, 0);
			}
			if(min_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_nine, COLOR08_RED, 35, 0);
			}

			if(hour_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_zero, COLOR08_RED, 33, 0);
			}
			if(hour_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_one, COLOR08_RED, 33, 0);
			}
			if(hour_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_two, COLOR08_RED, 33, 0);
			}
			if(hour_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_three, COLOR08_RED, 33, 0);
			}
			if(hour_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_four, COLOR08_RED, 33, 0);
			}
			if(hour_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_five, COLOR08_RED, 33, 0);
			}
			if(hour_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_six, COLOR08_RED, 33, 0);
			}
			if(hour_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_seven, COLOR08_RED, 33, 0);
			}
			if(hour_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_eight, COLOR08_RED, 33, 0);
			}
			if(hour_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_nine, COLOR08_RED, 33, 0);
			}




			if(hour_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_zero, COLOR08_RED, 32, 0);
			}
			if(hour_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_one, COLOR08_RED, 32, 0);
			}
			if(hour_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_two, COLOR08_RED, 32, 0);
			}
			if(hour_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_three, COLOR08_RED, 32, 0);
			}
			if(hour_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_four, COLOR08_RED, 32, 0);
			}
			if(hour_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_five, COLOR08_RED, 32, 0);
			}
			if(hour_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_six, COLOR08_RED, 32, 0);
			}
			if(hour_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_seven, COLOR08_RED, 32, 0);
			}
			if(hour_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_eight, COLOR08_RED, 32, 0);
			}
			if(hour_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_nine, COLOR08_RED, 32, 0);
			}

			if(day_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_zero, COLOR08_RED, 30, 0);
			}
			if(day_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_one, COLOR08_RED, 30, 0);
			}
			if(day_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_two, COLOR08_RED, 30, 0);
			}
			if(day_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_three, COLOR08_RED, 30, 0);
			}
			if(day_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_four, COLOR08_RED, 30, 0);
			}
			if(day_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_five, COLOR08_RED, 30, 0);
			}
			if(day_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_six, COLOR08_RED, 30, 0);
			}
			if(day_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_seven, COLOR08_RED, 30, 0);
			}
			if(day_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_eight, COLOR08_RED, 30, 0);
			}
			if(day_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_nine, COLOR08_RED, 30, 0);
			}




			if(day_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_zero, COLOR08_RED, 29, 0);
			}
			if(day_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_one, COLOR08_RED, 29, 0);
			}
			if(day_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_two, COLOR08_RED, 29, 0);
			}
			if(day_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_three, COLOR08_RED, 29, 0);
			}
			if(day_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_four, COLOR08_RED, 29, 0);
			}
			if(day_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_five, COLOR08_RED, 29, 0);
			}
			if(day_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_six, COLOR08_RED, 29, 0);
			}
			if(day_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_seven, COLOR08_RED, 29, 0);
			}
			if(day_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_eight, COLOR08_RED, 29, 0);
			}
			if(day_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_nine, COLOR08_RED, 29, 0);
			}

		}
		if(button==1 && y>0)//up
		{
			y--;
			draw(square, COLOR08_BLACK, x,y+3);
			printf("x: %i , y: %i , number %i \n", x, y, gameboard[y][x]);

			//y chords
			if(y==0)//0
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(zero, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==1)//1
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(one, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==2)//2
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(two, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==3)//3
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(three, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==4)//4
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(four, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==5)//5
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(five, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==6)//6
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(six, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==7)//7
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(seven, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}




		}

		if(button==2 && y<7)//down
		{
			y++;
			draw(square, COLOR08_BLACK, x,y+1);
			printf("x: %i , y: %i , number %i \n", x, y, gameboard[y][x]);

			//y chords
			if(y==0)//0
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(zero, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==1)//1
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(one, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==2)//2
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(two, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==3)//3
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(three, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==4)//4
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(four, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==5)//5
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(five, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==6)//6
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(six, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(y==7)//7
			{
				draw(white, COLOR08_BLACK, 19,1 );
				draw(seven, COLOR08_GRAY, 19,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

		}
		if(button==3 && x>0)//left
		{
			x--;
			draw(square, COLOR08_BLACK, x+1,y+2);
			printf("x: %i , y: %i , number %i \n", x, y, gameboard[y][x]);

			//x chords
			if(x==0)//0
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(zero, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==1)//1
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(one, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==2)//2
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(two, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==3)//3
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(three, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==4)//4
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(four, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==5)//5
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(five, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==6)//6
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(six, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==7)//7
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(seven, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==8)//8
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(eight, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==9)//9
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(nine, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==10)//10
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(zero, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==11)//11
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(one, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==12)//12
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(two, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==13)//13
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(three, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==14)//14
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(four, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==15)//15
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(five, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==16)//16
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(six, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==17)//17
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(seven, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==18)//18
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(eight, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==19)//19
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(nine, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}


		}
		if(button==4 && x<19)//right
		{
			x++;
			draw(square, COLOR08_BLACK, x-1,y+2);
			printf("x: %i , y: %i , number %i \n", x, y, gameboard[y][x]);

			//x chords
			if(x==0)//0
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(zero, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

			}

			if(x==1)//1
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(one, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==2)//2
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(two, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==3)//3
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(three, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==4)//4
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(four, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==5)//5
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(five, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==6)//6
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(six, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==7)//7
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(seven, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==8)//8
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(eight, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==9)//9
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(nine, COLOR08_GRAY, 2,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==10)//10
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(zero, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==11)//11
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(one, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==12)//12
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(two, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==13)//13
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(three, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==14)//14
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(four, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==15)//15
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(five, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==16)//16
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(six, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==17)//17
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(seven, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==18)//18
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(eight, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

			if(x==19)//19
			{
				draw(white, COLOR08_BLACK, 2,1 );
				draw(white, COLOR08_BLACK, 1,1 );
				draw(nine, COLOR08_GRAY, 2,1 );
				draw(one, COLOR08_GRAY, 1,1 );
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}

		}


		//gameboard select
		if(button==5)//gameboard

		{
			if(gameboard[y][x]==0)//0
						{

							//horizontal0
							if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==0 && gameboard[y][x+1]==-10) )//(0,0,0)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

							if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==0 && gameboard [y][x-1]==-10) || (gameboard [y][x]==0 && gameboard [y][x+1]==-10))//(
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

							if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y][x+1]==0 && gameboard[y][x+2]==-10)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							/////////////////////////////////

							//vertical0
							if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==0 && gameboard [y+1][x]==-10))//xmb
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

							if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==0 && gameboard [y+1][x]==-10))//txb
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

							if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==0 && gameboard [y-1][x]==-10))//tmx
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y-1][x]==0 && gameboard[y-2][x]==-10)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

			//////////////////////////////////////////////////////////////////

							//diagonal (\)0
							if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

							if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

							if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if ((gameboard[y][x]==0 && gameboard[y+1][x+1]==-10) || (gameboard[y][x]==0 && gameboard[y-1][x-1]==-10))//(\\x)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y-1][x-1]==0 && gameboard[y-2][x-2]==-10)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y+1][x+1]==0 && gameboard[y+2][x+2]==-10)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							//////////////////////////////////////////////////////////

							//diagonal (/)0
							if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

							}
							if (gameboard [y][x]==gameboard [y-1][x+1] && gameboard[y][x]== gameboard[y-2][x+2])//(x//)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if ((gameboard [y][x]==0 && gameboard [y+1][x-1]==-10) || (gameboard [y][x]==0 && gameboard [y-1][x+1]==-10))//(x//)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y+1][x-1]==0 && gameboard[y+2][x-2]==-10)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y-1][x+1]==0 && gameboard[y-2][x+2]==-10)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y+1][x-1]==0 && gameboard[y+2][x-2]==0)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}
							if(gameboard[y][x]==0 && gameboard[y-1][x+1]==0 && gameboard[y-2][x+2]==0)
							{
								draw(white, COLOR08_WHITE, x,y+2 );
								draw(zero, COLOR08_BLACK, x,y+2 );
								gameboard[y][x]=-10;
								IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
							}

						}

			if(gameboard[y][x]==1)//1
			{
				//horizontal1
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==1 && gameboard[y][x+1]==-11) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==1 && gameboard [y][x-1]==-11) || (gameboard [y][x]==1 && gameboard [y][x+1]==-11))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y][x+1]==1 && gameboard[y][x+2]==-11)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////

				//vertical1
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==1 && gameboard [y+1][x]==-11))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==1 && gameboard [y+1][x]==-11))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==1 && gameboard [y-1][x]==-11))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y-1][x]==1 && gameboard[y-2][x]==-11)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

//////////////////////////////////////////////////////////////////

				//diagonal (\)1
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==1 && gameboard[y+1][x+1]==-11) || (gameboard[y][x]==1 && gameboard[y-1][x-1]==-11))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y-1][x-1]==1 && gameboard[y-2][x-2]==-11)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y+1][x+1]==1 && gameboard[y+2][x+2]==-11)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////

				//diagonal (/)1
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if (gameboard [y][x]==gameboard [y-1][x+1] && gameboard[y][x]== gameboard[y-2][x+2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==1 && gameboard [y+1][x-1]==-11) || (gameboard [y][x]==1 && gameboard [y-1][x+1]==-11))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y+1][x-1]==1 && gameboard[y+2][x-2]==-11)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y-1][x+1]==1 && gameboard[y-2][x+2]==-11)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y+1][x-1]==1 && gameboard[y+2][x-2]==1)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==1 && gameboard[y-1][x+1]==1 && gameboard[y-2][x+2]==1)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(one, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-11;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}

			if(gameboard[y][x]==2)//2
			{
				//horizontal2
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==2 && gameboard[y][x+1]==-12) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==2 && gameboard [y][x-1]==-12) || (gameboard [y][x]==2 && gameboard [y][x+1]==-12))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y][x+1]==2 && gameboard[y][x+2]==-12)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////

				//vertical2
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==2 && gameboard [y+1][x]==-12))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==2 && gameboard [y+1][x]==-12))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==2 && gameboard [y-1][x]==-12))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y-1][x]==2 && gameboard[y-2][x]==-12)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

//////////////////////////////////////////////////////////////////

				//diagonal (\)2
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==2 && gameboard[y+1][x+1]==-12) || (gameboard[y][x]==2 && gameboard[y-1][x-1]==-12))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y-1][x-1]==2 && gameboard[y-2][x-2]==-12)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y+1][x+1]==2 && gameboard[y+2][x+2]==-12)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////

				//diagonal (/)2
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y-1][x+1] && gameboard[y][x]== gameboard[y-2][x+2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==2 && gameboard [y+1][x-1]==-12) || (gameboard [y][x]==2 && gameboard [y-1][x+1]==-12))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y+1][x-1]==2 && gameboard[y+2][x-2]==-12)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y-1][x+1]==2 && gameboard[y-2][x+2]==-12)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y+1][x-1]==2 && gameboard[y+2][x-2]==2)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==2 && gameboard[y-1][x+1]==2 && gameboard[y-2][x+2]==2)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(two, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-12;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}

			if(gameboard[y][x]==3)//3
			{
				//horizontal3
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==3 && gameboard[y][x+1]==-13) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==3 && gameboard [y][x-1]==-13) || (gameboard [y][x]==3 && gameboard [y][x+1]==-13))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==3 && gameboard[y][x+1]==3 && gameboard[y][x+2]==-13)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////

				//vertical3
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==3 && gameboard [y+1][x]==-13))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==3 && gameboard [y+1][x]==-13))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==3 && gameboard [y-1][x]==-13))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==3 && gameboard[y-1][x]==3 && gameboard[y-2][x]==-13)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

//////////////////////////////////////////////////////////////////

				//diagonal (\)3
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==3 && gameboard[y+1][x+1]==-13) || (gameboard[y][x]==3 && gameboard[y-1][x-1]==-13))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==3 && gameboard[y-1][x-1]==3 && gameboard[y-2][x-2]==-13)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==3 && gameboard[y+1][x+1]==3 && gameboard[y+2][x+2]==-13)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////

				//diagonal (/)3
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y-1][x+1] && gameboard[y][x]== gameboard[y-2][x+2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==3 && gameboard [y+1][x-1]==-13) || (gameboard [y][x]==3 && gameboard [y-1][x+1]==-13))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==3 && gameboard[y+1][x-1]==3 && gameboard[y+2][x-2]==-13)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==3 && gameboard[y-1][x+1]==3 && gameboard[y-2][x+2]==-13)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(three, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-13;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}

			if(gameboard[y][x]==4)//4
			{
				//horizontal4
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==4 && gameboard[y][x+1]==-14) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==4 && gameboard [y][x-1]==-14) || (gameboard [y][x]==4 && gameboard [y][x+1]==-14))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==4 && gameboard[y][x+1]==4 && gameboard[y][x+2]==-14)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////

				//vertical4
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==4 && gameboard [y+1][x]==-14))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==4 && gameboard [y+1][x]==-14))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==4 && gameboard [y-1][x]==-14))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==4 && gameboard[y-1][x]==4 && gameboard[y-2][x]==-14)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

//////////////////////////////////////////////////////////////////

				//diagonal (\)4
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==4 && gameboard[y+1][x+1]==-14) || (gameboard[y][x]==4 && gameboard[y-1][x-1]==-14))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==4 && gameboard[y-1][x-1]==4 && gameboard[y-2][x-2]==-14)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==4 && gameboard[y+1][x+1]==4 && gameboard[y+2][x+2]==-14)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////

				//diagonal (/)4
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y-1][x+1] && gameboard[y][x]== gameboard[y-2][x+2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==4 && gameboard [y+1][x-1]==-14) || (gameboard [y][x]==4 && gameboard [y-1][x+1]==-14))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==4 && gameboard[y+1][x-1]==4 && gameboard[y+2][x-2]==-14)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==4 && gameboard[y-1][x+1]==4 && gameboard[y-2][x+2]==-14)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(four, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-14;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}

			if(gameboard[y][x]==5)//5
			{
				//horizontal5
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==5 && gameboard[y][x+1]==-15) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==5 && gameboard [y][x-1]==-15) || (gameboard [y][x]==5 && gameboard [y][x+1]==-15))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==5 && gameboard[y][x+1]==5 && gameboard[y][x+2]==-15)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////

				//vertical5
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==5 && gameboard [y+1][x]==-15))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==5 && gameboard [y+1][x]==-15))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==5 && gameboard [y-1][x]==-15))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==5 && gameboard[y-1][x]==5 && gameboard[y-2][x]==-15)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

//////////////////////////////////////////////////////////////////

				//diagonal (\)5
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==5 && gameboard[y+1][x+1]==-15) || (gameboard[y][x]==5 && gameboard[y-1][x-1]==-15))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==5 && gameboard[y-1][x-1]==5 && gameboard[y-2][x-2]==-15)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==5 && gameboard[y+1][x+1]==5 && gameboard[y+2][x+2]==-15)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////

				//diagonal (/)5
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y-1][x+1] && gameboard[y][x]== gameboard[y-2][x+2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==5 && gameboard [y+1][x-1]==-15) || (gameboard [y][x]==5 && gameboard [y-1][x+1]==-15))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==5 && gameboard[y+1][x-1]==5 && gameboard[y+2][x-2]==-15)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if(gameboard[y][x]==5 && gameboard[y-1][x+1]==5 && gameboard[y-2][x+2]==-15)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(five, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-15;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}

			if(gameboard[y][x]==6)//6
			{
				//horizontal6
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==6 && gameboard[y][x+1]==-16) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==6 && gameboard [y][x-1]==-16) || (gameboard [y][x]==6 && gameboard [y][x+1]==-16))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////

				//vertical6
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==6 && gameboard [y+1][x]==-16))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==6 && gameboard [y+1][x]==-16))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==6 && gameboard [y-1][x]==-16))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

//////////////////////////////////////////////////////////////////

				//diagonal (\)6
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==6 && gameboard[y+1][x+1]==-16) || (gameboard[y][x]==6 && gameboard[y-1][x-1]==-16))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}

				//////////////////////////////////////////////////////////

				//diagonal (/)6
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y+2][x-2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==6 && gameboard [y+1][x-1]==-16) || (gameboard [y][x]==6 && gameboard [y-1][x+1]==-16))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(six, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-16;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}
			if(gameboard[y][x]==7)//7
			{
				//horizontal7
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==7 && gameboard[y][x+1]==-17) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==7 && gameboard [y][x-1]==-17) || (gameboard [y][x]==7 && gameboard [y][x+1]==-17))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////
				//vertical7
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==7 && gameboard [y+1][x]==-17))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==7 && gameboard [y+1][x]==-17))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==7 && gameboard [y-1][x]==-17))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
//////////////////////////////////////////////////////////////////
				//diagonal (\)7
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==7 && gameboard[y+1][x+1]==-17) || (gameboard[y][x]==7 && gameboard[y-1][x-1]==-17))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////
				//diagonal (/)7
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y+2][x-2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==7 && gameboard [y+1][x-1]==-17) || (gameboard [y][x]==7 && gameboard [y-1][x+1]==-17))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(seven, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-17;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}
			if(gameboard[y][x]==8)//8
			{
				//horizontal8
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==8 && gameboard[y][x+1]==-18) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==8 && gameboard [y][x-1]==-18) || (gameboard [y][x]==8 && gameboard [y][x+1]==-18))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////
				//vertical8
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==8 && gameboard [y+1][x]==-18))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==8 && gameboard [y+1][x]==-18))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==8 && gameboard [y-1][x]==-18))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
//////////////////////////////////////////////////////////////////
				//diagonal (\)8
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==8 && gameboard[y+1][x+1]==-18) || (gameboard[y][x]==8 && gameboard[y-1][x-1]==-18))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////
				//diagonal (/)8
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y+2][x-2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==8 && gameboard [y+1][x-1]==-18) || (gameboard [y][x]==8 && gameboard [y-1][x+1]==-18))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(eight, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-18;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}
			if(gameboard[y][x]==9)//9
			{
				//horizontal9
				if ((gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2]) || (gameboard[y][x]==9 && gameboard[y][x+1]==-19) )//(0,0,0)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x+1]) || (gameboard [y][x]==9 && gameboard [y][x-1]==-19) || (gameboard [y][x]==9 && gameboard [y][x+1]==-19))//(
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y][x-1] && gameboard [y][x]== gameboard [y][x-2]))//00x
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				/////////////////////////////////
				//vertical9
				if ((gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x]) || (gameboard [y][x]==9 && gameboard [y+1][x]==-19))//xmb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y+1][x]) || (gameboard [y][x]==9 && gameboard [y+1][x]==-19))//txb
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x] && gameboard [y][x]== gameboard [y-2][x]) || (gameboard [y][x]==9 && gameboard [y-1][x]==-19))//tmx
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
//////////////////////////////////////////////////////////////////
				//diagonal (\)9
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y+1][x+1]== gameboard[y+2][x+2]))//(\x\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y+1][x+1] && gameboard[y][x]== gameboard[y+2][x+2]) )//(x\\)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==gameboard [y-1][x-1] && gameboard[y][x]== gameboard[y-2][x-2]) )//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard[y][x]==9 && gameboard[y+1][x+1]==-19) || (gameboard[y][x]==9 && gameboard[y-1][x-1]==-19))//(\\x)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				//////////////////////////////////////////////////////////
				//diagonal (/)9
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y-1][x+1])//(/x/)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);

				}
				if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard[y][x]== gameboard[y+2][x-2])//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
				if ((gameboard [y][x]==9 && gameboard [y+1][x-1]==-19) || (gameboard [y][x]==9 && gameboard [y-1][x+1]==-19))//(x//)
				{
					draw(white, COLOR08_WHITE, x,y+2 );
					draw(nine, COLOR08_BLACK, x,y+2 );
					gameboard[y][x]=-19;
					IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				}
			}
		}
		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 0);
		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
		Delay_Pulse();
		button=IORD_ALTERA_AVALON_PIO_DATA(KEY_UDLRM_ENCODER_BASE);
		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 0);
		//deselect(Q+W)
		if(button==5 && button != 4)
		{
			if(gameboard[y][x]==-10)//0
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(zero, COLOR08_CYAN, x,y+2 );
				gameboard[y][x]=0;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-11)//1
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(one, COLOR08_GREEN, x,y+2 );
				gameboard[y][x]=1;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-12)//2
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(two, COLOR08_MAGENTA, x,y+2 );
				gameboard[y][x]=2;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-13)//3
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(three, COLOR08_PURPLE, x,y+2 );
				gameboard[y][x]=3;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-14)//4
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(four, COLOR08_GOLD, x,y+2 );
				gameboard[y][x]=4;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-15)//5
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(five, COLOR08_ORANGE, x,y+2 );
				gameboard[y][x]=5;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-16)//6
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(six, COLOR08_ROYALBLUE, x,y+2 );
				gameboard[y][x]=6;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-17)//7
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(seven, COLOR08_CRIMSON, x,y+2 );
				gameboard[y][x]=7;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-18)//8
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(eight, COLOR08_BLUE, x,y+2 );
				gameboard[y][x]=8;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
			if(gameboard[y][x]==-19)//9
			{
				draw(white, COLOR08_BLACK, x,y+2 );
				draw(nine, COLOR08_INDIGO, x,y+2 );
				gameboard[y][x]=9;
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
			}
		}
		/////////////////////////////////////////
		IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 0);
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 1);
				Delay_Pulse();
				button=IORD_ALTERA_AVALON_PIO_DATA(KEY_UDLRM_ENCODER_BASE);
				IOWR_ALTERA_AVALON_PIO_DATA (KEY_READ_REQ_BASE, 0);
		if(button==6)
		{
			for(x=0;x<18;x++)
			{
				for(y=0;y<8;y++)
				{

					if(gameboard[y][x]==-10 || gameboard[y][x]==-11 || gameboard[y][x]==-12 || gameboard[y][x]==-13 || gameboard[y][x]==-14 || gameboard[y][x]==-15 || gameboard[y][x]==-16 || gameboard[y][x]==-17 || gameboard[y][x]==-18 || gameboard[y][x]==-19)
					{
							draw(white,COLOR08_WHITE,x,y+2);
							draw(E,COLOR08_BLACK,x,y+2);
							gameboard[y][x] = -1;
							ct++;



					}
				}
			}
		}
		Delay_Medium();


		}
		/////////////
	}
}
for(z=0;z<7;z++)
{
for(x=0;x<18;x++)
{
	for(y=0;y<8;y++)
	{
		if(y>0 && y<=7)
		{
			clk = IORD_ALTERA_AVALON_PIO_DATA(DIGITAL_CLOCK_BASE);
			sec = clk%60;
			min = (clk/60)%60;
			hour = ((clk/60)/60)%24;
			day =  (((clk/60)/60)/24)%100;
			sec_a = sec/10;
			sec_b = sec%10;
			min_a = min/10;
			min_b = min%10;
			hour_a = hour/10;
			hour_b = hour%10;
			day_a = day/10;
			day_b = day%10;

			printf("%i:",day);
			printf("%i:",hour);
			printf("%i:",min);
			printf("%i\n",sec);

			if(sec_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_zero, COLOR08_RED, 39, 0);
			}
			if(sec_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_one, COLOR08_RED, 39, 0);
			}
			if(sec_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_two, COLOR08_RED, 39, 0);
			}
			if(sec_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_three, COLOR08_RED, 39, 0);
			}
			if(sec_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_four, COLOR08_RED, 39, 0);
			}
			if(sec_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_five, COLOR08_RED, 39, 0);
			}
			if(sec_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_six, COLOR08_RED, 39, 0);
			}
			if(sec_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_seven, COLOR08_RED, 39, 0);
			}
			if(sec_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_eight, COLOR08_RED, 39, 0);
			}
			if(sec_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 39, 0);
				draw1(dig_nine, COLOR08_RED, 39, 0);
			}




			if(sec_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_zero, COLOR08_RED, 38, 0);
			}
			if(sec_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_one, COLOR08_RED, 38, 0);
			}
			if(sec_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_two, COLOR08_RED, 38, 0);
			}
			if(sec_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_three, COLOR08_RED, 38, 0);
			}
			if(sec_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_four, COLOR08_RED, 38, 0);
			}
			if(sec_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_five, COLOR08_RED, 38, 0);
			}
			if(sec_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_six, COLOR08_RED, 38, 0);
			}
			if(sec_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_seven, COLOR08_RED, 38, 0);
			}
			if(sec_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_eight, COLOR08_RED, 38, 0);
			}
			if(sec_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 38, 0);
				draw1(dig_nine, COLOR08_RED, 38, 0);
			}


			if(min_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_zero, COLOR08_RED, 36, 0);
			}
			if(min_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_one, COLOR08_RED, 36, 0);
			}
			if(min_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_two, COLOR08_RED, 36, 0);
			}
			if(min_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_three, COLOR08_RED, 36, 0);
			}
			if(min_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_four, COLOR08_RED, 36, 0);
			}
			if(min_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_five, COLOR08_RED, 36, 0);
			}
			if(min_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_six, COLOR08_RED, 36, 0);
			}
			if(min_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_seven, COLOR08_RED, 36, 0);
			}
			if(min_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_eight, COLOR08_RED, 36, 0);
			}
			if(min_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 36, 0);
				draw1(dig_nine, COLOR08_RED, 36, 0);
			}




			if(min_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_zero, COLOR08_RED, 35, 0);
			}
			if(min_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_one, COLOR08_RED, 35, 0);
			}
			if(min_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_two, COLOR08_RED, 35, 0);
			}
			if(min_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_three, COLOR08_RED, 35, 0);
			}
			if(min_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_four, COLOR08_RED, 35, 0);
			}
			if(min_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_five, COLOR08_RED, 35, 0);
			}
			if(min_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_six, COLOR08_RED, 35, 0);
			}
			if(min_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_seven, COLOR08_RED, 35, 0);
			}
			if(min_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_eight, COLOR08_RED, 35, 0);
			}
			if(min_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 35, 0);
				draw1(dig_nine, COLOR08_RED, 35, 0);
			}

			if(hour_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_zero, COLOR08_RED, 33, 0);
			}
			if(hour_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_one, COLOR08_RED, 33, 0);
			}
			if(hour_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_two, COLOR08_RED, 33, 0);
			}
			if(hour_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_three, COLOR08_RED, 33, 0);
			}
			if(hour_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_four, COLOR08_RED, 33, 0);
			}
			if(hour_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_five, COLOR08_RED, 33, 0);
			}
			if(hour_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_six, COLOR08_RED, 33, 0);
			}
			if(hour_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_seven, COLOR08_RED, 33, 0);
			}
			if(hour_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_eight, COLOR08_RED, 33, 0);
			}
			if(hour_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 33, 0);
				draw1(dig_nine, COLOR08_RED, 33, 0);
			}




			if(hour_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_zero, COLOR08_RED, 32, 0);
			}
			if(hour_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_one, COLOR08_RED, 32, 0);
			}
			if(hour_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_two, COLOR08_RED, 32, 0);
			}
			if(hour_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_three, COLOR08_RED, 32, 0);
			}
			if(hour_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_four, COLOR08_RED, 32, 0);
			}
			if(hour_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_five, COLOR08_RED, 32, 0);
			}
			if(hour_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_six, COLOR08_RED, 32, 0);
			}
			if(hour_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_seven, COLOR08_RED, 32, 0);
			}
			if(hour_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_eight, COLOR08_RED, 32, 0);
			}
			if(hour_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 32, 0);
				draw1(dig_nine, COLOR08_RED, 32, 0);
			}

			if(day_b == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_zero, COLOR08_RED, 30, 0);
			}
			if(day_b == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_one, COLOR08_RED, 30, 0);
			}
			if(day_b == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_two, COLOR08_RED, 30, 0);
			}
			if(day_b == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_three, COLOR08_RED, 30, 0);
			}
			if(day_b == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_four, COLOR08_RED, 30, 0);
			}
			if(day_b == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_five, COLOR08_RED, 30, 0);
			}
			if(day_b == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_six, COLOR08_RED, 30, 0);
			}
			if(day_b == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_seven, COLOR08_RED, 30, 0);
			}
			if(day_b == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_eight, COLOR08_RED, 30, 0);
			}
			if(day_b == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 30, 0);
				draw1(dig_nine, COLOR08_RED, 30, 0);
			}




			if(day_a == 0)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_zero, COLOR08_RED, 29, 0);
			}
			if(day_a == 1)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_one, COLOR08_RED, 29, 0);
			}
			if(day_a == 2)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_two, COLOR08_RED, 29, 0);
			}
			if(day_a == 3)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_three, COLOR08_RED, 29, 0);
			}
			if(day_a == 4)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_four, COLOR08_RED, 29, 0);
			}
			if(day_a == 5)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_five, COLOR08_RED, 29, 0);
			}
			if(day_a == 6)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_six, COLOR08_RED, 29, 0);
			}
			if(day_a == 7)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_seven, COLOR08_RED, 29, 0);
			}
			if(day_a == 8)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_eight, COLOR08_RED, 29, 0);
			}
			if(day_a == 9)
			{
				draw1(dig_blank, COLOR08_BLACK, 29, 0);
				draw1(dig_nine, COLOR08_RED, 29, 0);
			}
		if(gameboard[y][x]==-1)
		{
			if(gameboard[y-1][x]==5)
			{
				//printf("top number before %i\n", gameboard[y-1][x]);
				//printf("top number before %i\n", gameboard[y][x]);
				draw(white,COLOR08_BLACK,x,y+1);
				gameboard[y][x]=gameboard[y-1][x];
				gameboard[y-1][x]=-1;
				//printf("top number after %i\n", gameboard[y-1][x]);
				//printf("top number after %i\n", gameboard[y][x]);
				if(gameboard[y][x] == 0)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(zero, COLOR08_CYAN, x, y+2);
				}
				if(gameboard[y][x] == 1)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(one, COLOR08_GREEN , x, y+2);
				}
				if(gameboard[y][x] == 2)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(two, COLOR08_MAGENTA , x, y+2);
				}
				if(gameboard[y][x] == 3)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(three, COLOR08_PURPLE, x, y+2);
				}
				if(gameboard[y][x] == 4)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(four, COLOR08_GOLD, x, y+2);
				}
			}
			if(gameboard[y-1][x]==4)
			{
				//printf("top number before %i\n", gameboard[y-1][x]);
				//printf("top number before %i\n", gameboard[y][x]);
				draw(white,COLOR08_BLACK,x,y+1);
				gameboard[y][x]=gameboard[y-1][x];
				gameboard[y-1][x]=-1;
				//printf("top number after %i\n", gameboard[y-1][x]);
				//printf("top number after %i\n", gameboard[y][x]);
				if(gameboard[y][x] == 0)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(zero, COLOR08_CYAN, x, y+2);
				}
				if(gameboard[y][x] == 1)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(one, COLOR08_GREEN , x, y+2);
				}
				if(gameboard[y][x] == 2)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(two, COLOR08_MAGENTA , x, y+2);
				}
				if(gameboard[y][x] == 3)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(three, COLOR08_PURPLE, x, y+2);
				}
				if(gameboard[y][x] == 4)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(four, COLOR08_GOLD, x, y+2);
				}
			}
			if(gameboard[y-1][x]==3)
			{
				//printf("top number before %i\n", gameboard[y-1][x]);
				//printf("top number before %i\n", gameboard[y][x]);
				draw(white,COLOR08_BLACK,x,y+1);
				gameboard[y][x]=gameboard[y-1][x];
				gameboard[y-1][x]=-1;
				//printf("top number after %i\n", gameboard[y-1][x]);
				//printf("top number after %i\n", gameboard[y][x]);
				if(gameboard[y][x] == 0)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(zero, COLOR08_CYAN, x, y+2);
				}
				if(gameboard[y][x] == 1)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(one, COLOR08_GREEN , x, y+2);
				}
				if(gameboard[y][x] == 2)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(two, COLOR08_MAGENTA , x, y+2);
				}
				if(gameboard[y][x] == 3)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(three, COLOR08_PURPLE, x, y+2);
				}
				if(gameboard[y][x] == 4)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(four, COLOR08_GOLD, x, y+2);
				}
			}
			if(gameboard[y-1][x]==2)
			{
				//printf("top number before %i\n", gameboard[y-1][x]);
				//printf("top number before %i\n", gameboard[y][x]);
				draw(white,COLOR08_BLACK,x,y+1);
				gameboard[y][x]=gameboard[y-1][x];
				gameboard[y-1][x]=-1;
				//printf("top number after %i\n", gameboard[y-1][x]);
				//printf("top number after %i\n", gameboard[y][x]);
				if(gameboard[y][x] == 0)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(zero, COLOR08_CYAN, x, y+2);
				}
				if(gameboard[y][x] == 1)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(one, COLOR08_GREEN , x, y+2);
				}
				if(gameboard[y][x] == 2)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(two, COLOR08_MAGENTA , x, y+2);
				}
				if(gameboard[y][x] == 3)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(three, COLOR08_PURPLE, x, y+2);
				}
				if(gameboard[y][x] == 4)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(four, COLOR08_GOLD, x, y+2);
				}

			}
			if(gameboard[y-1][x]==1)
			{
				//printf("top number before %i\n", gameboard[y-1][x]);
				//printf("top number before %i\n", gameboard[y][x]);
				draw(white,COLOR08_BLACK,x,y+1);
				gameboard[y][x]=gameboard[y-1][x];
				gameboard[y-1][x]=-1;
				//printf("top number after %i\n", gameboard[y-1][x]);
				//printf("top number after %i\n", gameboard[y][x]);
				if(gameboard[y][x] == 0)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(zero, COLOR08_CYAN, x, y+2);
				}
				if(gameboard[y][x] == 1)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(one, COLOR08_GREEN , x, y+2);
				}
				if(gameboard[y][x] == 2)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(two, COLOR08_MAGENTA , x, y+2);
				}
				if(gameboard[y][x] == 3)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(three, COLOR08_PURPLE, x, y+2);
				}
				if(gameboard[y][x] == 4)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(four, COLOR08_GOLD, x, y+2);
				}
			}
			if(gameboard[y-1][x]==0)
			{
				//printf("top number before %i\n", gameboard[y-1][x]);
				//printf("top number before %i\n", gameboard[y][x]);
				draw(white,COLOR08_BLACK,x,y+1);
				gameboard[y][x]=gameboard[y-1][x];
				gameboard[y-1][x]=-1;
				//printf("top number after %i\n", gameboard[y-1][x]);
				//printf("top number after %i\n", gameboard[y][x]);
				if(gameboard[y][x] == 0)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(zero, COLOR08_CYAN, x, y+2);
				}
				if(gameboard[y][x] == 1)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(one, COLOR08_GREEN , x, y+2);
				}
				if(gameboard[y][x] == 2)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(two, COLOR08_MAGENTA , x, y+2);
				}
				if(gameboard[y][x] == 3)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(three, COLOR08_PURPLE, x, y+2);
				}
				if(gameboard[y][x] == 4)
				{
					draw(white,COLOR08_BLACK,x,y+2);
					draw(four, COLOR08_GOLD, x, y+2);
				}
			}
		}
		}
	}
}
}
//Delay_Medium();
for(x=0;x<18;x++)
{
	for(y=0;y<8;y++)
	{
		if(gameboard[y][x]==-1)
		{
			draw(white,COLOR08_RED,x,y+2);
		}
	}
}
//Delay_Medium();
for(x=0;x<18;x++)
{
	for(y=0;y<8;y++)
	{
		nn = rand()%k;
		if(gameboard[y][x]==-1)
		{
			gameboard[y][x]=nn;
			if (nn == 0)
			{
				draw(white,COLOR08_BLACK,x,y+2);
				draw(zero, COLOR08_CYAN, x, y+2);
			}
			if (nn == 1)
			{
				draw(white,COLOR08_BLACK,x,y+2);
				draw(one, COLOR08_GREEN , x, y+2);
			}
			if (nn == 2)
			{
				draw(white,COLOR08_BLACK,x,y+2);
				draw(two, COLOR08_MAGENTA , x, y+2);
			}
			if (nn == 3)
			{
				draw(white,COLOR08_BLACK,x,y+2);
				draw(three, COLOR08_PURPLE, x, y+2);
			}
			if (nn == 4)
			{
				draw(white,COLOR08_BLACK,x,y+2);
				draw(four, COLOR08_GOLD, x, y+2);
			}
			if (nn == 5)
			{
				draw(white,COLOR08_BLACK,x,y+2);
				draw(five, COLOR08_ORANGE, x, y+2);
			}
			if (nn == 6)
			{
				draw(six, COLOR08_ROYALBLUE, x, y);
			}
			if (nn == 7)
			{
				draw(seven, COLOR08_CRIMSON, x, y);
			}
			if (nn == 8)
			{
				draw(eight, COLOR08_BLUE, x, y);
			}
			if (nn == 9)
			{
				draw(nine, COLOR08_INDIGO, x, y);
		}
	}
}
}
draw(white, COLOR08_BLACK, 19,1 );
draw(zero, COLOR08_GRAY, 19,1 );
draw(white, COLOR08_BLACK, 2,1 );
draw(zero, COLOR08_GRAY, 2,1 );
draw(white, COLOR08_BLACK, 1,1 );
draw(zero, COLOR08_GRAY, 1,1 );
if(ct>9999){
ct=1;
}
t=ct%10;
q=(ct/10);
q=q%10;
w=(ct/100);
w=w%10;
r=(ct/1000);
r=r%10;
if(t==0)
{
draw(white, COLOR08_BLACK,8,0);
draw(zero,COLOR08_WHITE, 8, 0);
}
if(t==1)
{
draw(white, COLOR08_BLACK,8,0);
draw(one,COLOR08_WHITE, 8, 0);
}
if(t==2)
{
draw(white, COLOR08_BLACK,8,0);
draw(two,COLOR08_WHITE, 8, 0);
}
if(t==3)
{
draw(white, COLOR08_BLACK,8,0);
draw(three,COLOR08_WHITE, 8, 0);
}
if(t==4)
{
draw(white, COLOR08_BLACK,8,0);
draw(four,COLOR08_WHITE, 8, 0);
}
if(t==5)
{
draw(white, COLOR08_BLACK,8,0);
draw(five,COLOR08_WHITE, 8, 0);
}
if(t==6)
{
draw(white, COLOR08_BLACK,8,0);
draw(six,COLOR08_WHITE, 8, 0);
}
if(t==7)
{
draw(white, COLOR08_BLACK,8,0);
draw(seven,COLOR08_WHITE, 8, 0);
}
if(t==8)
{
draw(white, COLOR08_BLACK,8,0);
draw(eight,COLOR08_WHITE, 8, 0);
}
if(t==9)
{
draw(white, COLOR08_BLACK,8,0);
draw(nine,COLOR08_WHITE, 8, 0);
}
if(q==0)
{
draw(white, COLOR08_BLACK,7,0);
draw(zero,COLOR08_WHITE, 7, 0);
}
if(q==1)
{
draw(white, COLOR08_BLACK,7,0);
draw(one,COLOR08_WHITE, 7, 0);
}
if(q==2)
{
draw(white, COLOR08_BLACK,7,0);
draw(two,COLOR08_WHITE, 7, 0);
}
if(q==3)
{
draw(white, COLOR08_BLACK,7,0);
draw(three,COLOR08_WHITE, 7, 0);
}
if(q==4)
{
draw(white, COLOR08_BLACK,7,0);
draw(four,COLOR08_WHITE, 7, 0);
}
if(q==5)
{
draw(white, COLOR08_BLACK,7,0);
draw(five,COLOR08_WHITE, 7, 0);
}
if(q==6)
{
draw(white, COLOR08_BLACK,7,0);
draw(six,COLOR08_WHITE, 7, 0);
}
if(q==7)
{
draw(white, COLOR08_BLACK,7,0);
draw(seven,COLOR08_WHITE, 7, 0);
}
if(q==8)
{
draw(white, COLOR08_BLACK,7,0);
draw(eight,COLOR08_WHITE, 7, 0);
}
if(q==9)
{
draw(white, COLOR08_BLACK,7,0);
draw(nine,COLOR08_WHITE, 7, 0);
}
if(w==0)
{
draw(white, COLOR08_BLACK,6,0);
draw(zero,COLOR08_WHITE, 6, 0);
}
if(w==1)
{
draw(white, COLOR08_BLACK,6,0);
draw(one,COLOR08_WHITE, 6, 0);
}
if(w==2)
{
draw(white, COLOR08_BLACK,6,0);
draw(two,COLOR08_WHITE, 6, 0);
}
if(w==3)
{
draw(white, COLOR08_BLACK,6,0);
draw(three,COLOR08_WHITE, 6, 0);
}
if(w==4)
{
draw(white, COLOR08_BLACK,6,0);
draw(four,COLOR08_WHITE, 6, 0);
}
if(w==5)
{
draw(white, COLOR08_BLACK,6,0);
draw(five,COLOR08_WHITE, 6, 0);
}
if(w==6)
{
draw(white, COLOR08_BLACK,6,0);
draw(six,COLOR08_WHITE, 6, 0);
}
if(w==7)
{
draw(white, COLOR08_BLACK,6,0);
draw(seven,COLOR08_WHITE, 6, 0);
}
if(w==8)
{
draw(white, COLOR08_BLACK, 6,0);
draw(eight,COLOR08_WHITE, 6, 0);
}
if(w==9)
{
draw(white, COLOR08_BLACK,6,0);
draw(nine,COLOR08_WHITE,  6, 0);
}
if(r==0)
{
draw(white, COLOR08_BLACK,5,0);
draw(zero,COLOR08_WHITE, 5, 0);
}
if(r==1)
{
draw(white, COLOR08_BLACK,5,0);
draw(one,COLOR08_WHITE, 5, 0);
}
if(r==2)
{
draw(white, COLOR08_BLACK,5,0);
draw(two,COLOR08_WHITE, 5, 0);
}
if(r==3)
{
draw(white, COLOR08_BLACK,5,0);
draw(three,COLOR08_WHITE, 5, 0);
}
if(r==4)
{
draw(white, COLOR08_BLACK,5,0);
draw(four,COLOR08_WHITE, 5, 0);
}
if(r==5)
{
draw(white, COLOR08_BLACK,5,0);
draw(five,COLOR08_WHITE, 5, 0);
}
if(r==6)
{
draw(white, COLOR08_BLACK,5,0);
draw(six,COLOR08_WHITE, 5, 0);
}
if(r==7)
{
draw(white, COLOR08_BLACK,5,0);
draw(seven,COLOR08_WHITE, 5, 0);
}
if(r==8)
{
draw(white, COLOR08_BLACK,5,0);
draw(eight,COLOR08_WHITE, 5, 0);
}
if(r==9)
{
draw(white, COLOR08_BLACK,5,0);
draw(nine,COLOR08_WHITE, 5, 0);
}
}
return 0;
}
