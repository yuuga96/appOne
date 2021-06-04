#if 1
#include"libOne.h"

struct DATA {
    int INIT = 0;
    int PLAY = 1;
    int RESULT = 2;
    int state = INIT;
};

void loadImages(struct DATA* d) {}
void init(struct DATA* d) {}
void play(struct DATA* d) {}
void result(struct DATA* d) {}
void draw(struct DATA* d) {}

void gmain() {
    window(800, 450);
    struct DATA d;
    loadImages(&d);
    while (notQuit) {
        if      (d.state == d.INIT  ) { init(&d); }
        else if (d.state == d.PLAY  ) { play(&d); }
        else if (d.state == d.RESULT) { result(&d); }
        draw(&d);
    }
}

#else

#include"libOne.h"

struct HAND {
    int hand;
    int img[3];
    int heartImg;
    float px;
    float py;
    struct COLOR color;
    float angle;
    int life;
};

struct RESULT_TEXT {
    const char* str;
    float px;
    float py;
    float size;
    struct COLOR color;
};

struct DATA {
    int INIT = 0;
    int PLAY = 1;
    int RESULT = 2;
    int state = INIT;

    struct COLOR pink = { 255,200,200 };
    struct COLOR white = { 255,255,255 };
    struct COLOR red = { 255,0,0 };
    struct COLOR blue = { 0,0,200 };
    int GU = 0;
    int CHOKI = 1;
    int PA = 2;
    struct HAND player;
    struct HAND pc;
    struct RESULT_TEXT resultText;
};

void drawHands(struct DATA* d);
void drawResultText(struct DATA* d);

void loadImages(struct DATA* d) {
    d->player.img[d->GU] = loadImage("assets\\playerGu.png");
    d->player.img[d->CHOKI] = loadImage("assets\\playerChoki.png");
    d->player.img[d->PA] = loadImage("assets\\playerPa.png");
    d->player.heartImg = loadImage("assets\\heart.png");
    d->pc.img[d->GU] = loadImage("assets\\pcGu.png");
    d->pc.img[d->CHOKI] = loadImage("assets\\pcChoki.png");
    d->pc.img[d->PA] = loadImage("assets\\pcPa.png");
    d->pc.heartImg = d->player.heartImg;
}
void init(struct DATA* d) {
    d->player.hand = d->GU;
    d->player.px = 250;
    d->player.py = 225;
    d->player.color = d->white;
    d->player.life = 3;
    d->player.angle = 0;

    d->pc.hand = d->GU;
    d->pc.px = 550;
    d->pc.py = 225;
    d->pc.color = d->white;
    d->pc.life = 3;
    d->pc.angle = 0;

    d->resultText.str = "����";
    d->resultText.color = d->red;
    d->resultText.px = 255;
    d->resultText.py = 320;
    d->resultText.size = 0;
    
    drawHands(d);

    //�X�e�[�g�؂�ւ�
    d->state = d->PLAY;
}
void play(struct DATA* d) {
    if (!isTrigger(KEY_A) && !isTrigger(KEY_S) && !isTrigger(KEY_D)) {
        return;
    }
    //�v���C���[�̎�
    if (isTrigger(KEY_A)) { d->player.hand = d->GU; }
    if (isTrigger(KEY_S)) { d->player.hand = d->CHOKI; }
    if (isTrigger(KEY_D)) { d->player.hand = d->PA; }
    //�o�b�̎�
    d->pc.hand = random() % 3;
    //���ʔ���
    if (d->player.hand == d->pc.hand) {
        //������
        d->player.color = d->white;
        d->pc.color = d->white;
    }
    else if ((d->player.hand + 1) % 3 == d->pc.hand) {
        //�v���C���[����
        d->pc.life--;
        d->player.color = d->pink;
        d->pc.color = d->white;
    }
    else {
        //�o�b����
        d->player.life--;
        d->player.color = d->white;
        d->pc.color = d->pink;
    }
    //�`��
    drawHands(d);
    //�X�e�[�g�؂�ւ�
    if (d->player.life == 0 || d->pc.life == 0) {
        if (d->player.life == 0) {
            d->resultText.str = "����";
            d->resultText.color = d->blue;
        }
        d->state = d->RESULT;
    }
}
void result(struct DATA* d) {
    //�������肪��]���Ȃ��痎���Ă���
    if (d->player.life == 0) {
        d->player.py += 1;
        d->player.angle += 0.003f;
    }
    else {
        d->pc.py += 1;
        d->pc.angle += -0.003f;
    }
    //���ʕ����g��
    if (d->resultText.size < 180) {
        d->resultText.size += 10;
    }
    //�`��
    drawHands(d);
    drawResultText(d);
    //�X�e�[�g�؂�ւ�
    if (isTrigger(KEY_SPACE)) {
        d->state = d->INIT;
    }
}

void drawHand(struct HAND* hand) {
    //��
    rectMode(CENTER);
    imageColor(hand->color);
    int i = hand->hand;
    image(hand->img[i], hand->px, hand->py, hand->angle);
    //�n�[�g
    imageColor(255, 0, 0);
    for (i = 0; i < hand->life; i++) {
        image(hand->heartImg, hand->px + 50 * (i - 1), hand->py - 100);
    }
}
void drawHands(struct DATA* d) {
    clear(180);
    drawHand(&d->player);
    drawHand(&d->pc);
}
void drawResultText(struct DATA* d) {
    textSize(d->resultText.size);
    fill(d->resultText.color);
    text(d->resultText.str, d->resultText.px, d->resultText.py);
}

void gmain() {
    //�E�B���h�E�\��
    window(800, 450);
    //�f�[�^�p��
    struct DATA d;
    //�摜�ǂݍ���
    loadImages(&d);
    //���C�����[�v
    while (notQuit) {
        //�X�e�[�g����
        if      (d.state == d.INIT  ) { init(&d); }
        else if (d.state == d.PLAY  ) { play(&d); }
        else if (d.state == d.RESULT) { result(&d); }
    }
}
#endif
