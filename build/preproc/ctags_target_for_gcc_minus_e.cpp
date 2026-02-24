# 1 "/home/fb/repos/server-ui-control/server-ui-control.ino"
# 2 "/home/fb/repos/server-ui-control/server-ui-control.ino" 2
# 3 "/home/fb/repos/server-ui-control/server-ui-control.ino" 2
# 4 "/home/fb/repos/server-ui-control/server-ui-control.ino" 2
# 5 "/home/fb/repos/server-ui-control/server-ui-control.ino" 2
# 6 "/home/fb/repos/server-ui-control/server-ui-control.ino" 2
# 25 "/home/fb/repos/server-ui-control/server-ui-control.ino"
unsigned int colors[] = {0x0000, 0x001F, 0xF800, 0x07E0, 0x07FF, 0xF81F, 0xFFE0, 0xFFFF};

MCUFRIEND_kbv tft;

const int XP = 8, XM = A2, YP = A3, YM = 9; //ID=0x9341
const int TS_LEFT = 136, TS_RT = 907, TS_TOP = 942, TS_BOT = 139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

Adafruit_GFX_Button on_btn, off_btn;

int pixel_x, pixel_y; //Touch_getXY() updates global vars

int width = 320;
int height = 480;

bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, 0x1); //restore shared pins
    pinMode(XM, 0x1);
    digitalWrite(YP, 0x1); //because TFT control pins
    digitalWrite(XM, 0x1);
    bool pressed = (p.z > 200 && p.z < 1000);
    if (pressed) {
        pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}

void setup()
{
 Serial.begin(9600);
    uint16_t ID = tft.readID();
    tft.begin(ID);
    tft.setRotation(1);
    tft.fillScreen(0x0000);

    width = tft.width();
    height = tft.height();
}

void loop()
{

}
