from flask import Flask, render_template, jsonify, request
import serial
import time

app = Flask(__name__)

try:
    ser = serial.Serial('/dev/cu.usbmodem1101', 9600, timeout=1)
    time.sleep(2)  
except:
    print("Error: Could not open serial port!")
    ser = None

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/move_servo', methods=['POST'])
def move_servo():
    if ser is None:
        return jsonify({'status': 'error', 'message': 'Serial connection not available'})
    
    data = request.get_json()
    servo_num = data.get('servo')
    angle = data.get('angle')
    
    if servo_num is None or angle is None:
        return jsonify({'status': 'error', 'message': 'Invalid parameters'})
    
    # Send command to Arduino
    command = f"{servo_num},{angle}\n"
    ser.write(command.encode())
    
    # Wait for and read the response
    time.sleep(0.1)
    response = ser.readline().decode().strip()
    
    return jsonify({'status': 'success', 'response': response})

if __name__ == '__main__':
    app.run(debug=True)

