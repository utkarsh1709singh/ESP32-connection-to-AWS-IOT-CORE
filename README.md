# ESP32-connection-to-AWS-IOT-CORE

Overview
This README provides a step-by-step guide for connecting an ESP32 microcontroller to AWS IoT Core using the MQTT (Message Queuing Telemetry Transport) protocol. The ESP32 will be configured to securely communicate with AWS IoT Core, enabling the exchange of messages between the device and the AWS Cloud.

Prerequisites
Before proceeding, ensure you have the following:

An AWS account with IoT Core service enabled.
An IoT Thing created in AWS IoT Core.
X.509 certificates and private key for the Thing obtained from AWS IoT Core.
WiFi network credentials (SSID and password).
Arduino IDE installed on your development machine.
Setup
Install Required Libraries:

Open Arduino IDE and install the following libraries via the Library Manager:

ArduinoJson
PubSubClient
WiFi
Include Certificates and WiFi Credentials:

Add your X.509 certificates and private key obtained from AWS IoT Core to the "certs.h" file. Additionally, provide your WiFi network credentials in the "WiFi.h" file.

Include Required Libraries:

Include the necessary libraries in your Arduino sketch:

Set the AWS IoT Core endpoint, publish topic, and subscribe topic:

Call the connectAWS function in the setup routine:

Use the publishMessage function to publish messages to AWS IoT Core:

Building and Flashing
Compile and upload your sketch to the ESP32 board using the Arduino IDE.

Monitoring
Open the Arduino IDE Serial Monitor to observe the device's connection status, published messages, and incoming messages.

Conclusion
Your ESP32 device is now securely connected to AWS IoT Core. The provided code demonstrates the basic setup for MQTT communication with AWS IoT, and you can expand it based on your specific use case and requirements.

For more information on AWS IoT Core and ESP32, refer to the official documentation of AWS IoT and the ESP32 Arduino Core.
