# Dual 7-Segment Counter with Direction Control

An Arduino-based counter project featuring dual 7-segment displays, potentiometer controls for speed and direction, and LED indicators.

## 🛠️ Components Used

- 1x Arduino Uno
- 2x 7-segment displays
- 2x CD4511 BCD to 7-segment decoders
- 2x Potentiometers
- 1x Green LED
- 1x Red LED
- Resistors (220Ω)
- Jumper Wires
- 1x Breadboard

## 📋 Features

- Dual 7-segment display (00-99 range)
- Adjustable counting speed via potentiometer
- Direction control (up/down) via potentiometer
- LED direction indicators (Green for up, Red for down)
- BCD encoding for display control

## 🎮 Pin Configuration

### Display Control
- First Display (segment1): pins 2, 3, 4, 5
- Second Display (segment2): pins 6, 7, 8, 9
- Direction LEDs:
  - Green LED: pin 11
  - Red LED: pin 10

### Input Controls
- Speed Potentiometer: A0
- Direction Potentiometer: A1

## 📺 Circuit Diagram

![Ödev2](https://github.com/user-attachments/assets/dcfb6826-d379-414c-beae-c091db105a72)



## 💡 Usage

1. Power up the Arduino board
2. Adjust left potentiometer to control counting speed
3. Adjust right potentiometer to control counting direction:
   - Left half: Count down
   - Right half: Count up
4. Green LED indicates counting up
5. Red LED indicates counting down
6. Display shows numbers from 00 to 99

## ⚡ How It Works

1. **Direction Control**
   - Potentiometer reading < 512: Count down
   - Potentiometer reading > 512: Count up

2. **Speed Control**
   - Maps potentiometer value (0-1023) to delay (200ms-1000ms)

3. **Display System**
   - Dual 7-segment displays using BCD encoding
   - Updates continuously based on counter value

## ⚠️ Important Notes

- Ensure correct BCD decoder connections
- Verify potentiometer wiring
- Check LED polarity
- Use appropriate current-limiting resistors
- Counter limits: 00 to 99

## 🔧 Assembly Instructions

1. **Display Setup**
   - Connect 7-segment displays via BCD decoders
   - Wire segment control pins correctly
   - Add current-limiting resistors

2. **Control Setup**
   - Wire potentiometers to analog pins
   - Connect direction indicator LEDs
   - Verify ground connections


## 🔍 Troubleshooting

| Problem | Possible Solution |
|---------|------------------|
| Displays show wrong numbers | Check BCD connections |
| Counter not responding | Verify potentiometer connections |
| LEDs not working | Check polarity and resistors |
| Erratic counting | Clean potentiometer contacts |


## 🔄 Version History

- v1.0 (Initial Release)
  - Basic counter functionality
  - Speed and direction control
  - LED indicators
 
## 📝 License

This project is licensed under the MIT License 
