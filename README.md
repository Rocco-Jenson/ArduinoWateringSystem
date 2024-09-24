# Arduino Watering System

This project is an automated watering system that uses a moisture sensor to check the soil’s moisture level. If the soil is detected as dry, the system turns on a water pump to deliver water to the plants until the soil is sufficiently moist.

### Functionality
- The moisture sensor regularly checks the soil's moisture level.
- If the soil is dry (below a specified threshold), the relay activates the water pump.
- The pump waters the soil until the moisture level reaches a satisfactory value, at which point the pump turns off.
- The system operates autonomously and can be left to manage the watering of plants without user intervention.

## System Architecture

1. **Moisture Detection**:
   - The moisture sensor continuously reads the soil’s moisture level.
   - The sensor output is an analog signal, where a low value means dry soil and a high value means moist soil.

2. **Water Pump Control**:
   - When the moisture level falls below a predefined threshold, the relay is triggered, turning on the water pump.
   - The water pump remains on until the moisture sensor reads a value above the threshold, then it automatically turns off to prevent over-watering.
