digitalWrite(motorF, <IN1 value>);
digitalWrite(motorB, <IN2 value>);

// 直走向前
digitalWrite(motorRF, 255);
digitalWrite(motorRB, 0);
digitalWrite(motorLF, 255);
digitalWrite(motorLB, 0);

// 原地左轉
digitalWrite(motorRF, 255);
digitalWrite(motorRB, 0);
digitalWrite(motorLF, 0);
digitalWrite(motorLB, 255);

// 行進中右拐
digitalWrite(motorRF, 100);
digitalWrite(motorRB, 0);
digitalWrite(motorLF, 200);
digitalWrite(motorLB, 0);


int btn_state = 0; // Button State
int btnSwitch[2] = {0, 0}; // Button State Queue

{
    btn_state = digitalRead(pBtn); // Read Current Button State

    btnSwitch[0] = btnSwitch[1]; // Queue Pop
    btnSwitch[1] = btn_state;  // Queue Push

    if (btnSwitch[0] == HIGH && btnSwitch[1] == LOW) ... // Button Up, Initialize

    ...
}