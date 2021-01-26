#include <graphics.h>
#include <dos.h>

namespace greeting
{
    void Welcome()
    {
        initwindow(800, 800);
        setcolor(14);
        delay(100);
        //W
        line(10, 50, 10, 150);
        line(10, 150, 35, 100);
        line(35, 100, 60, 150);
        line(60, 150, 60, 50);
        setcolor(3);
        delay(100);
        //E
        line(70, 50, 70, 150);
        line(70, 50, 110, 50);
        line(70, 150, 110, 150);
        line(70, 100, 90, 100);
        setcolor(9);
        delay(100);
        //L
        line(120, 50, 120, 150);
        line(120, 150, 160, 150);
        setcolor(9);
        delay(100);
        //C
        ellipse(200, 100, 90, 270, 40, 50);
        setcolor(10);
        delay(100);
        //O
        ellipse(250, 100, 0, 360, 30, 50);
        setcolor(11);
        delay(100);
        //M
        line(290, 50, 290, 150);
        line(290, 50, 315, 100);
        line(315, 100, 340, 50);
        line(340, 50, 340, 150);
        setcolor(12);
        delay(100);
        //E
        line(350, 50, 350, 150);
        line(350, 50, 390, 50);
        line(350, 150, 390, 150);
        line(350, 100, 365, 100);
        setcolor(13);
        delay(100);
        //T
        line(420, 50, 460, 50);
        line(440, 50, 440, 150);
        setcolor(14);
        delay(100);
        //O
        ellipse(480, 100, 0, 360, 30, 50);
        setcolor(14);
        delay(100);
        //S
        ellipse(42, 275, 30, 270, 30, 30);
        ellipse(35, 333, 180, 360, 30, 30);
        ellipse(35, 333, 0, 80, 30, 30);
        setcolor(3);
        delay(100);
        //H
        line(80, 250, 80, 350);
        line(80, 300, 120, 300);
        line(120, 250, 120, 350);
        setcolor(9);
        delay(100);
        //O
        ellipse(160, 300, 0, 360, 30, 50);
        setcolor(10);
        delay(100);
        //P
        line(200, 250, 200, 350);
        ellipse(200, 280, 270, 90, 30, 30);
        setcolor(10);
        delay(100);
        //P
        line(240, 250, 240, 350);
        ellipse(240, 280, 270, 90, 30, 30);
        setcolor(11);
        delay(100);
        //I
        line(280, 255, 320, 255);
        line(300, 255, 300, 345);
        line(280, 345, 320, 345);
        setcolor(12);
        delay(100);
        //N
        line(330, 250, 330, 350);
        line(370, 250, 370, 350);
        line(330, 250, 370, 350);
        setcolor(13);
        delay(100);
        //G
        ellipse(405, 300, 60, 360, 25, 50);
        line(415, 300, 445, 300);
        line(445, 300, 445, 325);
        setcolor(14);
        delay(100);
        //C
        ellipse(50, 500, 90, 270, 40, 50);
        setcolor(3);
        delay(100);
        //L
        line(70, 450, 70, 550);
        line(70, 550, 110, 550);
        setcolor(9);
        delay(100);
        //U
        ellipse(160, 450, 180, 360, 30, 100);
        setcolor(10);
        delay(100);
        //B
        line(220, 450, 220, 550);
        ellipse(220, 475, 270, 90, 40, 25);
        ellipse(220, 525, 270, 90, 40, 25);
        delay(100);

        //SOMETHING
        setcolor(14);
        line(320, 450, 305, 650);
        line(540, 450, 555, 600);
        line(320, 450, 540, 450);
        line(365, 750, 475, 750);
        setcolor(15);
        delay(100);
        circle(350, 500, 5);
        circle(490, 500, 5);
        ellipse(420, 500, 180, 360, 70, 70);
        setcolor(3);
        delay(100);
        line(270, 650, 255, 750);
        line(350, 650, 365, 750);
        line(270, 650, 350, 650);
        line(255, 750, 365, 750);
        setcolor(15);
        delay(100);
        circle(290, 665, 2);
        circle(330, 665, 2);
        ellipse(310, 665, 180, 360, 20, 20);
        setcolor(13);
        delay(100);
        line(490, 600, 475, 750);
        line(610, 600, 625, 750);
        line(490, 600, 610, 600);
        line(475, 750, 625, 750);
        setcolor(15);
        delay(100);
        circle(520, 625, 3);
        circle(580, 625, 3);
        ellipse(550, 625, 180, 360, 30, 30);
    } // namespace Welcome

    void Thankyou()
    {
        initwindow(400, 400);

        //T
        setcolor(10);
        line(70, 50, 70, 150);
        delay(100);
        line(50, 50, 90, 50);
        delay(100);

        //H
        setcolor(3);
        line(100, 50, 100, 150);
        delay(100);
        line(140, 50, 140, 150);
        delay(100);
        line(100, 100, 140, 100);
        delay(100);

        //A
        setcolor(12);
        line(170, 50, 150, 150);
        delay(100);
        line(170, 50, 190, 150);
        delay(100);
        line(160, 100, 180, 100);
        delay(100);

        //N
        setcolor(3);
        line(200, 50, 200, 150);
        delay(100);
        line(240, 50, 240, 150);
        delay(100);
        line(240, 150, 200, 50);
        delay(100);

        //K
        setcolor(14);
        line(250, 50, 250, 150);
        delay(100);
        line(250, 100, 280, 50);
        delay(100);
        line(250, 100, 280, 150);
        delay(100);

        //Y
        setcolor(10);
        line(100, 250, 120, 300);
        delay(100);
        line(140, 250, 120, 300);
        delay(100);
        line(120, 300, 120, 350);
        delay(100);

        //O
        setcolor(12);
        ellipse(170, 300, 0, 360, 20, 50);
        delay(100);

        //U
        setcolor(14);
        ellipse(220, 250, 180, 360, 20, 100);
        delay(100);

        getch();
    } // namespace Thankyou
} // namespace greeting
