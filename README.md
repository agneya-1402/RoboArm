# RoboArm Control Hub - Arduino & Flask Web Interface

A modern web-based control system for a 4-DOF robotic arm using Arduino and Flask. This project provides an intuitive GUI interface to control a KUKA-style robotic arm with precision and ease.

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Python](https://img.shields.io/badge/python-3.11-green.svg)
![Arduino](https://img.shields.io/badge/arduino-IDE%202.0+-red.svg)

## 🤖 Features

- Real-time servo control through web interface
- 4 degrees of freedom (DOF) control
- Intuitive slider-based interface
- Cross-platform compatibility

### Hardware Requirements
- Arduino board (Uno recommended)
- 4 servo motors
- KUKA-style robotic arm frame
- USB cable

### Software Requirements
- Python 3.11.4 or higher
- Arduino IDE 2.0+
- Modern web browser
- Operating System: macOS (M1), Windows, or Linux

## 🛠️ Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/agneya-1402/RoboArm.git
   cd RoboArm
   ```

2. **Install Python dependencies**
   ```bash
   pip install -r requirements.txt
   ```

3. **Upload Arduino Code**
   - Open `arduino/arm_1.ino` in Arduino IDE
   - Select your board and port
   - Upload the code

4. **Configure Serial Port**
   - For M1 MacBook:
     - Check port name in Arduino IDE (usually `/dev/cu.usbmodem1101`)
     - Update `app.py` with correct port name

## 📂 Project Structure
```
RoboArm/
├── arduino/
│   └── Arm_1.ino
│       
├── templates/
│   └── index.html
├── app.py
└── README.md
```

## 🚀 Usage

1. **Start the Flask server**
   ```bash
   python app.py
   ```

2. **Access the control interface**
   - Open your web browser
   - Navigate to `http://127.0.0.1:5000`

3. **Control the robotic arm**
   - Use sliders to control each servo:
     - Servo 1: Base rotation (0-180°)
     - Servo 2: Arm segment 1 (0-180°)
     - Servo 3: Arm segment 2 (0-180°)
     - Servo 4: Claw control (0-180°)

## 🔌 Pin Configuration

| Servo     | Arduino Pin | Function        |
|-----------|-------------|-----------------|
| Servo 1   | 8           | Base rotation   |
| Servo 2   | 9           | Arm 1 movement  |
| Servo 3   | 10          | Arm 2 movement  |
| Servo 4   | 11          | Claw control    |

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## ⚠️ Safety Notes

- Always ensure the robotic arm has adequate clearance before operation
- Start with slow movements when testing new positions
- Keep fingers clear of the claw mechanism
- Ensure proper power supply to prevent servo jitter

## 🐛 Troubleshooting

1. **Serial Port Connection Issues**
   - Verify the correct port in Arduino IDE
   - Check USB connection
   - Ensure proper permissions on the serial port

2. **Servo Movement Problems**
   - Verify power supply adequacy
   - Check servo wire connections
   - Ensure servo positions are within limits

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details

## 🙏 Acknowledgments

- Inspired by KUKA robotic arms
- Built with Flask framework
- Arduino Servo library
- Serial communication protocol
