# Dual-Axis Solar Tracking System

<!--
  Dual-Axis Solar Tracker
  README – Professional Edition
  © 2025 Burak Mertek & contributors
-->


# Dual-Axis Solar Tracker

A compact, **Arduino Nano–powered**, dual-axis platform that keeps a solar panel perpendicular to sunlight throughout the day, boosting energy yield by up to **40 %** compared with fixed mounting systems.  
The project is fully open-source (hardware, firmware and 3-D models) and can be adapted to larger arrays or educational demonstrations.

---

## Table of Contents
1. [Key Features](#key-features)  
2. [Bill of Materials](#bill-of-materials)  
3. [Repository Layout](#repository-layout)  
4. [Quick Start](#quick-start)  
5. [Calibration & Operation](#calibration--operation)  
6. [Performance](#performance)  
7. [Contributing](#contributing)  
8. [Roadmap](#roadmap)  
9. [Authors & Credits](#authors--credits)  
10. [License](#license)  

---

## Key Features
- **Dual-axis tracking** &nbsp;— &nbsp;independent azimuth and elevation control  
- **Four-quadrant LDR array** for fine sun-vector detection (no RTC needed)  
- **Real-time power logging** with INA219; data streamed over Serial or saved to SD (optional)  
- **0.96" OLED dashboard** for instantaneous voltage, current and efficiency read-outs  
- **Li-ion power pack** with TP4056 charging/USB load sharing  
- **Lightweight 3-D-printed chassis**; printable on any 120 × 120 mm bed  
- **Modular firmware** (Arduino/C++) + a **Python helper** to simulate sun position offline  

---

## Bill of Materials

| Qty | Component | Reference | Est. Unit € |
|-----|-----------|-----------|-------------|
| 1   | Arduino Nano V3 - CH340 | MCU | 4.50 |
| 2   | SG90 micro-servo (180 °) | Pan / Tilt | 3.20 |
| 4   | LDR GL5537 + 10 kΩ divider | Light sensors | 0.20 |
| 1   | INA219 current/voltage sensor | Power monitor | 2.40 |
| 1   | 0.96-inch I²C OLED 128×64 | Display | 4.00 |
| 1   | TP4056 Li-ion charger/5 V booster | Battery mngt. | 1.50 |
| 1   | 3.7 V 1200 mAh Li-Po cell | Battery | 5.00 |
| 1   | 6 V 150 mA polycrystalline panel | PV module | 6.00 |
| —   | M3 × 16 mm screws, standoffs, wires | Hardware | 2.00 |

<sub>Total ≈ **€30** (2025 retail)</sub>

Full schematic and part links are in **`/hardware`**.

---

## Repository Layout

```
├── src/
│   ├── solar_tracker.ino      # Main tracking control code
│   ├── power_logger.ino       # Power monitoring system
│   └── solar_position.py      # Solar position calculation (Python)
├── hardware/
│   ├── circuit_diagram.png    # Circuit schematic
│   └── components_list.md     # Detailed component specifications
├── 3d_models/
│   ├── pan_tilt_base.stl     # 3D printable base
│   ├── pan_tilt_platform.stl # 3D printable platform
│   └── pan_tilt_top.stl      # 3D printable top piece
└── docs/
    ├── setup_guide.md        # Assembly and setup instructions
    └── performance_data.md   # Test results and analysis

```


---

## Quick Start

| Step | Action | Reference |
|------|--------|-----------|
| 1 | **Print** the three STL parts and gather components | [`/3d_models`](3d_models) |
| 2 | **Wire** the circuit following `circuit_diagram.png` | [`/hardware`](hardware) |
| 3 | **Flash** `src/solar_tracker.ino` to the Nano | Arduino IDE / PlatformIO |
| 4 | **Power up**, place unit under sunlight and verify OLED read-outs | On-device |
| 5 | **(Optional)** start `solar_position.py` to compare theoretical vs. measured orientation | Python 3.9+ |

> **Tip:** If the servos jitter on USB power alone, connect a separate 5 V supply capable of 1 A.

---

## Calibration & Operation

1. **LDR Alignment** – use the built-in “level mode” (hold the left button for 3 s) to zero the ADC offsets.  
2. **Servo Limits** – edit `PAN_MIN`, `PAN_MAX`, `TILT_MIN`, `TILT_MAX` in *`solar_tracker.ino`* for your mechanics.  
3. **Data Logging** – compile `power_logger.ino` if you want to stream CSV to a computer or log to SD.  
4. **Storage** – park position is automatically set at sunset to protect the panel from overnight wind loads.

---

## Performance

| Metric | Tracker | Fixed-tilt panel | Gain |
|--------|---------|------------------|------|
| Average daily Wh (May, Ankara) | 2.81 Wh | 2.01 Wh | **+39.8 %** |
| Servo consumption | 4.2 mAh/day | — | n/a |
| Tracking error (mean) | **≤ 2 °** | — | — |

<details>
  <summary>Why only ~40 %?</summary>
  The diminutive panel saturates around noon; bigger panels are current-limited by the battery charger. A full-size rooftop system can see 25 – 30 % yearly gain, but this desktop model is optimised for demonstration and low cost.
</details>

Further plots and raw data are in **`docs/performance_data.md`**.

---

## Contributing

1. **Fork** the repo and create a feature branch (`git checkout -b feature/your-idea`).  
2. Follow the **Arduino style guide** (`.clang-format`) and the **PTAL** commit convention.  
3. Run `platformio check` before opening a pull request.  
4. Sign off your commits (`git commit -s`) to agree to the MIT license.

Bug reports and feature requests are welcome via **GitHub Issues**.

---

## Roadmap

- [ ] Add optional GPS + RTC fallback for low-light tracking  
- [ ] Integrate an ESP32 variant with Wi-Fi telemetry  
- [ ] KiCad hardware redesign (all-in-one PCB)  
- [ ] Continuous-integration workflow for automated firmware builds  

Feel free to open an issue if you are interested in tackling one of these tasks!

---

## Authors & Credits
- Çağatay Yılmaz  
- Fatih Yiğit  
- Recep Kutlay Tumay  
- **Burak Metin Mertek** *(maintainer)*  
<br>Supervisor: **Prof. Dr. Zıyodulla Yusupov**

Special thanks to everyone who tested prototypes and provided feedback.

---

## License
This project is distributed under the terms of the **MIT License**.  
See [`LICENSE`](LICENSE) for full text.

