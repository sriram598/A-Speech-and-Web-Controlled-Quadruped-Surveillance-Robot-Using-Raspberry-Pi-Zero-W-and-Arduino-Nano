#include <Servo.h>

// =====================================================
// SPYDER ROBOT - WOKWI VERSION
// Arduino Nano + 12 Servos
// =====================================================

Servo servo[4][3];

const int servo_pin[4][3] = {
  {3, 4, 2},
  {6, 7, 5},
  {9, 8, 10},
  {12, 11, 13}
};

// Robot dimensions
const float length_a = 55;
const float length_b = 77.5;
const float length_c = 27.5;
const float length_side = 71;
const float z_absolute = -28;

// Movement constants
const float z_default = -50;
const float z_up = -30;
const float z_boot = z_absolute;

const float x_default = 62;
const float x_offset = 0;

const float y_start = 0;
const float y_step = 40;
const float y_default = x_default;

// Movement variables
float site_now[4][3];
float site_expect[4][3];
float temp_speed[4][3];

float move_speed;
float speed_multiple = 1;

const float spot_turn_speed = 4;
const float leg_move_speed = 8;
const float body_move_speed = 3;
const float stand_seat_speed = 1;

int rest_counter = 0;

const float KEEP = 255;
const float pi = 3.1415926;

// Turn calculations
const float temp_a =
  sqrt(pow(2 * x_default + length_side, 2) + pow(y_step, 2));

const float temp_b =
  2 * (y_start + y_step) + length_side;

const float temp_c =
  sqrt(pow(2 * x_default + length_side, 2) +
       pow(2 * y_start + y_step + length_side, 2));

const float temp_alpha =
  acos((pow(temp_a, 2) + pow(temp_b, 2) -
        pow(temp_c, 2)) / 2 / temp_a / temp_b);

const float turn_x1 = (temp_a - length_side) / 2;
const float turn_y1 = y_start + y_step / 2;

const float turn_x0 =
  turn_x1 - temp_b * cos(temp_alpha);

const float turn_y0 =
  temp_b * sin(temp_alpha) - turn_y1 - length_side;


// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(115200);

  Serial.println("SPYDER ROBOT START");

  // Initial leg positions
  set_site(0, x_default - x_offset, y_start + y_step, z_boot);
  set_site(1, x_default - x_offset, y_start + y_step, z_boot);
  set_site(2, x_default + x_offset, y_start, z_boot);
  set_site(3, x_default + x_offset, y_start, z_boot);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      site_now[i][j] = site_expect[i][j];
    }
  }

  servo_attach();

  // Put servos at initial position
  servo_service();

  Serial.println("SERVOS INITIALIZED");

  delay(1000);
}


// =====================================================
// SERVO ATTACH
// =====================================================

void servo_attach()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].attach(servo_pin[i][j]);
      delay(50);
    }
  }
}


void servo_detach()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].detach();
      delay(50);
    }
  }
}


// =====================================================
// MAIN LOOP
// =====================================================

void loop()
{
  Serial.println("STAND");
  stand();
  delay(2000);

  Serial.println("STEP FORWARD");
  step_forward(5);
  delay(2000);

  Serial.println("STEP BACK");
  step_back(5);
  delay(2000);

  Serial.println("TURN LEFT");
  turn_left(5);
  delay(2000);

  Serial.println("TURN RIGHT");
  turn_right(5);
  delay(2000);

  Serial.println("HAND WAVE");
  hand_wave(3);
  delay(2000);

  Serial.println("HAND SHAKE");
  hand_shake(3);
  delay(2000);

  Serial.println("BODY DANCE");
  body_dance(10);
  delay(2000);

  Serial.println("SIT");
  sit();
  delay(5000);
}


// =====================================================
// SIT
// =====================================================

void sit()
{
  move_speed = stand_seat_speed;

  for (int leg = 0; leg < 4; leg++)
  {
    set_site(leg, KEEP, KEEP, z_boot);
  }

  wait_all_reach();
}


// =====================================================
// STAND
// =====================================================

void stand()
{
  move_speed = stand_seat_speed;

  for (int leg = 0; leg < 4; leg++)
  {
    set_site(leg, KEEP, KEEP, z_default);
  }

  wait_all_reach();
}


// =====================================================
// TURN LEFT
// =====================================================

void turn_left(unsigned int step)
{
  move_speed = spot_turn_speed;

  while (step-- > 0)
  {
    if (site_now[3][1] == y_start)
    {
      set_site(3, x_default + x_offset, y_start, z_up);
      wait_all_reach();

      set_site(0, turn_x1 - x_offset, turn_y1, z_default);
      set_site(1, turn_x0 - x_offset, turn_y0, z_default);
      set_site(2, turn_x1 + x_offset, turn_y1, z_default);
      set_site(3, turn_x0 + x_offset, turn_y0, z_up);
      wait_all_reach();

      set_site(3, turn_x0 + x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(0, turn_x1 + x_offset, turn_y1, z_default);
      set_site(1, turn_x0 + x_offset, turn_y0, z_default);
      set_site(2, turn_x1 - x_offset, turn_y1, z_default);
      set_site(3, turn_x0 - x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(1, turn_x0 + x_offset, turn_y0, z_up);
      wait_all_reach();

      set_site(0, x_default + x_offset, y_start, z_default);
      set_site(1, x_default + x_offset, y_start, z_up);
      set_site(2, x_default - x_offset, y_start + y_step, z_default);
      set_site(3, x_default - x_offset, y_start + y_step, z_default);
      wait_all_reach();

      set_site(1, x_default + x_offset, y_start, z_default);
      wait_all_reach();
    }
    else
    {
      set_site(0, x_default + x_offset, y_start, z_up);
      wait_all_reach();

      set_site(0, turn_x0 + x_offset, turn_y0, z_up);
      set_site(1, turn_x1 + x_offset, turn_y1, z_default);
      set_site(2, turn_x0 - x_offset, turn_y0, z_default);
      set_site(3, turn_x1 - x_offset, turn_y1, z_default);
      wait_all_reach();

      set_site(0, turn_x0 + x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(0, turn_x0 - x_offset, turn_y0, z_default);
      set_site(1, turn_x1 - x_offset, turn_y1, z_default);
      set_site(2, turn_x0 + x_offset, turn_y0, z_default);
      set_site(3, turn_x1 + x_offset, turn_y1, z_default);
      wait_all_reach();

      set_site(2, turn_x0 + x_offset, turn_y0, z_up);
      wait_all_reach();

      set_site(0, x_default - x_offset, y_start + y_step, z_default);
      set_site(1, x_default - x_offset, y_start + y_step, z_default);
      set_site(2, x_default + x_offset, y_start, z_up);
      set_site(3, x_default + x_offset, y_start, z_default);
      wait_all_reach();

      set_site(2, x_default + x_offset, y_start, z_default);
      wait_all_reach();
    }
  }
}


// =====================================================
// TURN RIGHT
// =====================================================

void turn_right(unsigned int step)
{
  move_speed = spot_turn_speed;

  while (step-- > 0)
  {
    if (site_now[2][1] == y_start)
    {
      set_site(2, x_default + x_offset, y_start, z_up);
      wait_all_reach();

      set_site(0, turn_x0 - x_offset, turn_y0, z_default);
      set_site(1, turn_x1 - x_offset, turn_y1, z_default);
      set_site(2, turn_x0 + x_offset, turn_y0, z_up);
      set_site(3, turn_x1 + x_offset, turn_y1, z_default);
      wait_all_reach();

      set_site(2, turn_x0 + x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(0, turn_x0 + x_offset, turn_y0, z_default);
      set_site(1, turn_x1 + x_offset, turn_y1, z_default);
      set_site(2, turn_x0 - x_offset, turn_y0, z_default);
      set_site(3, turn_x1 - x_offset, turn_y1, z_default);
      wait_all_reach();

      set_site(0, turn_x0 + x_offset, turn_y0, z_up);
      wait_all_reach();

      set_site(0, x_default + x_offset, y_start, z_up);
      set_site(1, x_default + x_offset, y_start, z_default);
      set_site(2, x_default - x_offset, y_start + y_step, z_default);
      set_site(3, x_default - x_offset, y_start + y_step, z_default);
      wait_all_reach();

      set_site(0, x_default + x_offset, y_start, z_default);
      wait_all_reach();
    }
    else
    {
      set_site(1, x_default + x_offset, y_start, z_up);
      wait_all_reach();

      set_site(0, turn_x1 + x_offset, turn_y1, z_default);
      set_site(1, turn_x0 + x_offset, turn_y0, z_up);
      set_site(2, turn_x1 - x_offset, turn_y1, z_default);
      set_site(3, turn_x0 - x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(1, turn_x0 + x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(0, turn_x1 - x_offset, turn_y1, z_default);
      set_site(1, turn_x0 - x_offset, turn_y0, z_default);
      set_site(2, turn_x1 + x_offset, turn_y1, z_default);
      set_site(3, turn_x0 + x_offset, turn_y0, z_default);
      wait_all_reach();

      set_site(3, turn_x0 + x_offset, turn_y0, z_up);
      wait_all_reach();

      set_site(0, x_default - x_offset, y_start + y_step, z_default);
      set_site(1, x_default - x_offset, y_start + y_step, z_default);
      set_site(2, x_default + x_offset, y_start, z_default);
      set_site(3, x_default + x_offset, y_start, z_up);
      wait_all_reach();

      set_site(3, x_default + x_offset, y_start, z_default);
      wait_all_reach();
    }
  }
}


// =====================================================
// WALK FORWARD
// =====================================================

void step_forward(unsigned int step)
{
  move_speed = leg_move_speed;

  while (step-- > 0)
  {
    if (site_now[2][1] == y_start)
    {
      set_site(2, x_default + x_offset, y_start, z_up);
      wait_all_reach();

      set_site(2, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(2, x_default + x_offset,
               y_start + 2 * y_step, z_default);
      wait_all_reach();

      move_speed = body_move_speed;

      set_site(0, x_default + x_offset,
               y_start, z_default);

      set_site(1, x_default + x_offset,
               y_start + 2 * y_step, z_default);

      set_site(2, x_default - x_offset,
               y_start + y_step, z_default);

      set_site(3, x_default - x_offset,
               y_start + y_step, z_default);

      wait_all_reach();

      move_speed = leg_move_speed;

      set_site(1, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(1, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(1, x_default + x_offset,
               y_start, z_default);
      wait_all_reach();
    }
    else
    {
      set_site(0, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(0, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(0, x_default + x_offset,
               y_start + 2 * y_step, z_default);
      wait_all_reach();

      move_speed = body_move_speed;

      set_site(0, x_default - x_offset,
               y_start + y_step, z_default);

      set_site(1, x_default - x_offset,
               y_start + y_step, z_default);

      set_site(2, x_default + x_offset,
               y_start, z_default);

      set_site(3, x_default + x_offset,
               y_start + 2 * y_step, z_default);

      wait_all_reach();

      move_speed = leg_move_speed;

      set_site(3, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(3, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(3, x_default + x_offset,
               y_start, z_default);
      wait_all_reach();
    }
  }
}


// =====================================================
// WALK BACK
// =====================================================

void step_back(unsigned int step)
{
  move_speed = leg_move_speed;

  while (step-- > 0)
  {
    if (site_now[3][1] == y_start)
    {
      set_site(3, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(3, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(3, x_default + x_offset,
               y_start + 2 * y_step, z_default);
      wait_all_reach();

      move_speed = body_move_speed;

      set_site(0, x_default + x_offset,
               y_start + 2 * y_step, z_default);

      set_site(1, x_default + x_offset,
               y_start, z_default);

      set_site(2, x_default - x_offset,
               y_start + y_step, z_default);

      set_site(3, x_default - x_offset,
               y_start + y_step, z_default);

      wait_all_reach();

      move_speed = leg_move_speed;

      set_site(0, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(0, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(0, x_default + x_offset,
               y_start, z_default);
      wait_all_reach();
    }
    else
    {
      set_site(1, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(1, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(1, x_default + x_offset,
               y_start + 2 * y_step, z_default);
      wait_all_reach();

      move_speed = body_move_speed;

      set_site(0, x_default - x_offset,
               y_start + y_step, z_default);

      set_site(1, x_default - x_offset,
               y_start + y_step, z_default);

      set_site(2, x_default + x_offset,
               y_start + 2 * y_step, z_default);

      set_site(3, x_default + x_offset,
               y_start, z_default);

      wait_all_reach();

      move_speed = leg_move_speed;

      set_site(2, x_default + x_offset,
               y_start + 2 * y_step, z_up);
      wait_all_reach();

      set_site(2, x_default + x_offset,
               y_start, z_up);
      wait_all_reach();

      set_site(2, x_default + x_offset,
               y_start, z_default);
      wait_all_reach();
    }
  }
}


// =====================================================
// BODY LEFT
// =====================================================

void body_left(int i)
{
  set_site(0, site_now[0][0] + i, KEEP, KEEP);
  set_site(1, site_now[1][0] + i, KEEP, KEEP);
  set_site(2, site_now[2][0] - i, KEEP, KEEP);
  set_site(3, site_now[3][0] - i, KEEP, KEEP);

  wait_all_reach();
}


// =====================================================
// BODY RIGHT
// =====================================================

void body_right(int i)
{
  set_site(0, site_now[0][0] - i, KEEP, KEEP);
  set_site(1, site_now[1][0] - i, KEEP, KEEP);
  set_site(2, site_now[2][0] + i, KEEP, KEEP);
  set_site(3, site_now[3][0] + i, KEEP, KEEP);

  wait_all_reach();
}


// =====================================================
// HAND WAVE
// =====================================================

void hand_wave(int i)
{
  float x_tmp;
  float y_tmp;
  float z_tmp;

  move_speed = 1;

  if (site_now[3][1] == y_start)
  {
    body_right(15);

    x_tmp = site_now[2][0];
    y_tmp = site_now[2][1];
    z_tmp = site_now[2][2];

    move_speed = body_move_speed;

    for (int j = 0; j < i; j++)
    {
      set_site(2, turn_x1, turn_y1, 50);
      wait_all_reach();

      set_site(2, turn_x0, turn_y0, 50);
      wait_all_reach();
    }

    set_site(2, x_tmp, y_tmp, z_tmp);
    wait_all_reach();

    move_speed = 1;
    body_left(15);
  }
  else
  {
    body_left(15);

    x_tmp = site_now[0][0];
    y_tmp = site_now[0][1];
    z_tmp = site_now[0][2];

    move_speed = body_move_speed;

    for (int j = 0; j < i; j++)
    {
      set_site(0, turn_x1, turn_y1, 50);
      wait_all_reach();

      set_site(0, turn_x0, turn_y0, 50);
      wait_all_reach();
    }

    set_site(0, x_tmp, y_tmp, z_tmp);
    wait_all_reach();

    move_speed = 1;
    body_right(15);
  }
}


// =====================================================
// HAND SHAKE
// =====================================================

void hand_shake(int i)
{
  float x_tmp;
  float y_tmp;
  float z_tmp;

  move_speed = 1;

  if (site_now[3][1] == y_start)
  {
    body_right(15);

    x_tmp = site_now[2][0];
    y_tmp = site_now[2][1];
    z_tmp = site_now[2][2];

    move_speed = body_move_speed;

    for (int j = 0; j < i; j++)
    {
      set_site(2, x_default - 30,
               y_start + 2 * y_step, 55);
      wait_all_reach();

      set_site(2, x_default - 30,
               y_start + 2 * y_step, 10);
      wait_all_reach();
    }

    set_site(2, x_tmp, y_tmp, z_tmp);
    wait_all_reach();

    move_speed = 1;
    body_left(15);
  }
  else
  {
    body_left(15);

    x_tmp = site_now[0][0];
    y_tmp = site_now[0][1];
    z_tmp = site_now[0][2];

    move_speed = body_move_speed;

    for (int j = 0; j < i; j++)
    {
      set_site(0, x_default - 30,
               y_start + 2 * y_step, 55);
      wait_all_reach();

      set_site(0, x_default - 30,
               y_start + 2 * y_step, 10);
      wait_all_reach();
    }

    set_site(0, x_tmp, y_tmp, z_tmp);
    wait_all_reach();

    move_speed = 1;
    body_right(15);
  }
}


// =====================================================
// HEAD UP
// =====================================================

void head_up(int i)
{
  set_site(0, KEEP, KEEP, site_now[0][2] - i);
  set_site(1, KEEP, KEEP, site_now[1][2] + i);
  set_site(2, KEEP, KEEP, site_now[2][2] - i);
  set_site(3, KEEP, KEEP, site_now[3][2] + i);

  wait_all_reach();
}


// =====================================================
// HEAD DOWN
// =====================================================

void head_down(int i)
{
  set_site(0, KEEP, KEEP, site_now[0][2] + i);
  set_site(1, KEEP, KEEP, site_now[1][2] - i);
  set_site(2, KEEP, KEEP, site_now[2][2] + i);
  set_site(3, KEEP, KEEP, site_now[3][2] - i);

  wait_all_reach();
}


// =====================================================
// BODY DANCE
// =====================================================

void body_dance(int i)
{
  float body_dance_speed = 2;

  sit();

  move_speed = 1;

  set_site(0, x_default, y_default, KEEP);
  set_site(1, x_default, y_default, KEEP);
  set_site(2, x_default, y_default, KEEP);
  set_site(3, x_default, y_default, KEEP);

  wait_all_reach();

  set_site(0, x_default, y_default,
           z_default - 20);
  set_site(1, x_default, y_default,
           z_default - 20);
  set_site(2, x_default, y_default,
           z_default - 20);
  set_site(3, x_default, y_default,
           z_default - 20);

  wait_all_reach();

  move_speed = body_dance_speed;

  head_up(30);

  for (int j = 0; j < i; j++)
  {
    if (j > i / 4)
      move_speed = body_dance_speed * 2;

    if (j > i / 2)
      move_speed = body_dance_speed * 3;

    set_site(0, KEEP, y_default - 20, KEEP);
    set_site(1, KEEP, y_default + 20, KEEP);
    set_site(2, KEEP, y_default - 20, KEEP);
    set_site(3, KEEP, y_default + 20, KEEP);

    wait_all_reach();

    set_site(0, KEEP, y_default + 20, KEEP);
    set_site(1, KEEP, y_default - 20, KEEP);
    set_site(2, KEEP, y_default + 20, KEEP);
    set_site(3, KEEP, y_default - 20, KEEP);

    wait_all_reach();
  }

  move_speed = body_dance_speed;

  head_down(30);
}


// =====================================================
// SERVO SERVICE
// =====================================================
// Wokwi version: replaces FlexiTimer2
// =====================================================

void servo_service()
{
  static float alpha;
  static float beta;
  static float gamma;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (abs(site_now[i][j] - site_expect[i][j])
          >= abs(temp_speed[i][j]))
      {
        site_now[i][j] += temp_speed[i][j];
      }
      else
      {
        site_now[i][j] = site_expect[i][j];
      }
    }

    cartesian_to_polar(
      alpha,
      beta,
      gamma,
      site_now[i][0],
      site_now[i][1],
      site_now[i][2]
    );

    polar_to_servo(
      i,
      alpha,
      beta,
      gamma
    );
  }

  rest_counter++;
}


// =====================================================
// SET SITE
// =====================================================

void set_site(int leg, float x, float y, float z)
{
  float length_x = 0;
  float length_y = 0;
  float length_z = 0;

  if (x != KEEP)
    length_x = x - site_now[leg][0];

  if (y != KEEP)
    length_y = y - site_now[leg][1];

  if (z != KEEP)
    length_z = z - site_now[leg][2];

  float length = sqrt(
    pow(length_x, 2) +
    pow(length_y, 2) +
    pow(length_z, 2)
  );

  // Prevent division by zero
  if (length < 0.001)
  {
    temp_speed[leg][0] = 0;
    temp_speed[leg][1] = 0;
    temp_speed[leg][2] = 0;
  }
  else
  {
    temp_speed[leg][0] =
      length_x / length * move_speed * speed_multiple;

    temp_speed[leg][1] =
      length_y / length * move_speed * speed_multiple;

    temp_speed[leg][2] =
      length_z / length * move_speed * speed_multiple;
  }

  if (x != KEEP)
    site_expect[leg][0] = x;

  if (y != KEEP)
    site_expect[leg][1] = y;

  if (z != KEEP)
    site_expect[leg][2] = z;
}


// =====================================================
// WAIT ONE LEG
// =====================================================

void wait_reach(int leg)
{
  while (true)
  {
    servo_service();

    if (site_now[leg][0] == site_expect[leg][0] &&
        site_now[leg][1] == site_expect[leg][1] &&
        site_now[leg][2] == site_expect[leg][2])
    {
      break;
    }

    delay(20);
  }
}


// =====================================================
// WAIT ALL LEGS
// =====================================================

void wait_all_reach()
{
  for (int i = 0; i < 4; i++)
  {
    wait_reach(i);
  }
}


// =====================================================
// CARTESIAN TO POLAR
// =====================================================

void cartesian_to_polar(
  float &alpha,
  float &beta,
  float &gamma,
  float x,
  float y,
  float z
)
{
  float v;
  float w;

  w = (x >= 0 ? 1 : -1) *
      sqrt(pow(x, 2) + pow(y, 2));

  v = w - length_c;

  float r = sqrt(
    pow(v, 2) +
    pow(z, 2)
  );

  float value1 =
    (pow(length_a, 2) -
     pow(length_b, 2) +
     pow(v, 2) +
     pow(z, 2))
    / (2 * length_a * r);

  float value2 =
    (pow(length_a, 2) +
     pow(length_b, 2) -
     pow(v, 2) -
     pow(z, 2))
    / (2 * length_a * length_b);

  // Keep acos input safe
  value1 = constrain(value1, -1.0, 1.0);
  value2 = constrain(value2, -1.0, 1.0);

  alpha =
    atan2(z, v) +
    acos(value1);

  beta =
    acos(value2);

  if (w >= 0)
    gamma = atan2(y, x);
  else
    gamma = atan2(-y, -x);

  alpha = alpha / pi * 180;
  beta = beta / pi * 180;
  gamma = gamma / pi * 180;
}


// =====================================================
// POLAR TO SERVO
// =====================================================

void polar_to_servo(
  int leg,
  float alpha,
  float beta,
  float gamma
)
{
  if (leg == 0)
  {
    alpha = 90 - alpha;
    beta = beta;
    gamma += 90;
  }
  else if (leg == 1)
  {
    alpha += 90;
    beta = 180 - beta;
    gamma = 90 - gamma;
  }
  else if (leg == 2)
  {
    alpha += 90;
    beta = 180 - beta;
    gamma = 90 - gamma;
  }
  else if (leg == 3)
  {
    alpha = 90 - alpha;
    beta = beta;
    gamma += 90;
  }

  // Keep servo values within normal range
  alpha = constrain(alpha, 0, 180);
  beta = constrain(beta, 0, 180);
  gamma = constrain(gamma, 0, 180);

  servo[leg][0].write((int)alpha);
  servo[leg][1].write((int)beta);
  servo[leg][2].write((int)gamma);
}