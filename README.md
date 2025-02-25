# Control de Ventilador con ESP32 y Blynk

Este proyecto utiliza un ESP32 para monitorear la temperatura, humedad y presión del ambiente mediante un sensor BME280 y controlar un ventilador de manera automática o manual a través de Blynk.

## 🚀 Características
- Monitoreo de temperatura, humedad y presión con el sensor BME280.
- Envío de datos en tiempo real a Blynk.
- Activación automática del ventilador si la temperatura supera los 28°C.
- Control manual del ventilador desde la app de Blynk.

## 📦 Requisitos
### 🔧 Hardware
- ESP32
- Sensor BME280
- Relevador (Relay) para el control del ventilador
- Cables de conexión

### 🖥️ Software
- Arduino IDE
- Biblioteca Blynk (`BlynkSimpleEsp32.h`)
- Biblioteca Adafruit BME280 (`Adafruit_BME280.h`)

## 📜 Instalación
### 1️⃣ Configurar Arduino IDE
1. Instala el **ESP32 Board Manager** en el Administrador de Tarjetas de Arduino.
2. Instala las siguientes bibliotecas desde el Administrador de Bibliotecas:
   - **Blynk**
   - **Adafruit BME280**
   - **Adafruit Sensor**

### 2️⃣ Configurar Blynk
1. Descarga la aplicación **Blynk** en tu dispositivo móvil.
2. Crea un nuevo proyecto y selecciona ESP32 como dispositivo.
3. Obtén el **BLYNK_AUTH_TOKEN** desde la app y reemplázalo en el código.

### 3️⃣ Cargar el Código en el ESP32
1. Conecta el ESP32 a la computadora.
2. Abre el código en el Arduino IDE.
3. Reemplaza los valores de **SSID** y **contraseña** de tu red WiFi en el código.
4. Sube el código al ESP32.

## ⚙️ Funcionamiento
- **Automático:** Si la temperatura supera los **28°C**, el ventilador se activa automáticamente.
- **Manual:** Desde la app de **Blynk**, el usuario puede activar o desactivar el ventilador con un botón virtual.

## 🔄 Conexiones del Circuito
| ESP32 Pin | Componente |
|-----------|-----------|
| 5         | Relay (Ventilador) |
| 21        | SDA (BME280) |
| 22        | SCL (BME280) |
| 3.3V      | VCC (BME280) |
| GND       | GND (BME280 y Relay) |

## 📷 Ejemplo de Visualización en Blynk
Blynk mostrará:
- **V1:** Temperatura
- **V2:** Humedad
- **V3:** Presión
- **V4:** Estado del ventilador (1 = Encendido, 0 = Apagado)

## 🚨 Notas
- Si el sensor BME280 no es detectado, revisa las conexiones y asegúrate de que su dirección I2C es `0x76`.
- Modifica el umbral de temperatura en el código si necesitas otro valor para activar el ventilador.

## 📌 Autor
Proyecto desarrollado por el grupo 1:
-Aldair Rivera
-Davis Cartagena
-Eva Bayes
-José Sernaqué
-Said Najarro

