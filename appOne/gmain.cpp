#define _EX
#ifdef _EX

#include"libOne.h"

void gmain() {
    window(1920, 1080, full);
    //�����p�f�[�^
    struct EXPLOSION {
        float px, py, angle, scale;
        int interval, counter = -1;
    };
    const int numExplosions = 30;
    struct EXPLOSION e[numExplosions];
    int triggerCnt = 0;
    int triggerInterval = 10;
    //�摜�f�[�^
    const  int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        imgs[i] = loadImage(filename);
    }

    while (notQuit) {

        //�����g���K�[
        ++triggerCnt %= triggerInterval;
        if (triggerCnt == 0) {
            for (int i = 0; i < numExplosions; i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2 - 200,width / 2 +200);
                    e[i].py = random(height / 2 - 100,height / 2 +100);
                    e[i].angle = random(6.28f);
                    e[i].scale = random(5,10);
                    e[i].interval = random(1,3);
                    e[i].counter = 0;
                    i = numExplosions;
                }
            }
        }
        //�����i�s
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                e[i].counter++;
                //�����I��
                if (e[i].counter >= e[i].interval * numImgs) {
                    e[i].counter = -1;
                }
            }
        }
        //�`��
        clear();
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                rectMode(CENTER);
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }
        }
    }
}

#endif

















#ifdef _SAMPLE1
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�L�����f�[�^
    float px = width / 2, py = height / 2, angle = 0, scale = 1.0f;
    int counter = -1, interval = 8;
    //�摜�ԍ��z��f�[�^
    const int numImgs = 8;
    int imgs[numImgs];
    //�摜�ǂݍ���
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\lady\\a%d.png", i);
        imgs[i] = loadImage(filename);
    }
    //���C�����[�v
    ShowCursor(false);
    while (notQuit) {
        int maxFrame = interval * numImgs;
        ++counter %= maxFrame;
        int no = counter / interval;
        //�`��
        clear(200, 160, 200);
        rectMode(CENTER);
        image(imgs[no], px, py, angle, scale);
    }
    ShowCursor(true);
}
#endif

#ifdef _SAMPLE2
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�����f�[�^
    struct EXPLOSION {
        float px, py, angle, scale;
        int interval, counter = -1;
    };
    const int numExplosions = 30;
    struct EXPLOSION e[numExplosions];
    int triggerCnt = 0;
    int triggerInterval = 5;
    //�摜�f�[�^
    const int numImgs = 60;
    int imgs[numImgs];
    for (int i = 0; i < numImgs; i++) {
        char filename[32];
        sprintf_s(filename, "assets\\explosion\\a%02d.png", i);
        imgs[i] = loadImage(filename);
    }
    ShowCursor(false);
    while (notQuit) {
        //�����J�n
        ++triggerCnt %= triggerInterval;
        if (triggerCnt == 0) {
            for (int i = 0; i < numExplosions; i++) {
                if (e[i].counter == -1) {
                    e[i].px = random(width / 2 - 150, width / 2 + 150);
                    e[i].py = random(height / 2 - 100, height / 2 + 100);
                    e[i].angle = random(3.14f * 2);
                    e[i].scale = random(5.0f, 10.0f);
                    e[i].interval = random(1, 3);
                    e[i].counter = 0;
                    i = numExplosions;
                }
            }
        }
        //�����i�s
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                ++e[i].counter;
                //�����I��
                if (e[i].counter >= e[i].interval * numImgs) {
                    e[i].counter = -1;
                }
            }
        }
        //�`��
        clear(60, 120, 240);
        rectMode(CENTER);
        for (int i = 0; i < numExplosions; i++) {
            if (e[i].counter >= 0) {
                int no = e[i].counter / e[i].interval;
                image(imgs[no], e[i].px, e[i].py, e[i].angle, e[i].scale);
            }
        }
    }
    ShowCursor(true);
}
#endif