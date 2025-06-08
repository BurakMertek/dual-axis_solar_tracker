"""
Solar Position Calculation
Python script for calculating sun's elevation and azimuth angles
based on geographic location, date, and time.

This can be used for advanced solar tracking algorithms.
"""

import ephem
import math
from datetime import datetime

def calculate_solar_position(latitude, longitude, date, time):
    """
    Calculate the sun's elevation and azimuth angles.
    
    Args:
        latitude (float): Latitude in degrees
        longitude (float): Longitude in degrees  
        date (str): Date in YYYY-MM-DD format
        time (str): Time in HH:MM:SS format
    
    Returns:
        tuple: (elevation, azimuth) in degrees
    """
    observer = ephem.Observer()
    observer.lat = str(latitude)
    observer.lon = str(longitude)
    observer.date = str(date) + " " + str(time)
    
    sun = ephem.Sun()
    sun.compute(observer)
    
    elevation = sun.alt * 180 / ephem.pi
    azimuth = sun.az * 180 / ephem.pi
    
    return elevation, azimuth

def get_servo_angles(elevation, azimuth):
    """
    Convert solar angles to servo motor angles.
    
    Args:
        elevation (float): Sun elevation angle in degrees
        azimuth (float): Sun azimuth angle in degrees
    
    Returns:
        tuple: (horizontal_servo_angle, vertical_servo_angle)
    """
    # Map elevation (0-90°) to vertical servo range
    vertical_angle = max(0, min(90, elevation))
    
    # Map azimuth (0-360°) to horizontal servo range
    horizontal_angle = azimuth % 360
    
    return horizontal_angle, vertical_angle

def main():
    """
    Example usage of solar position calculation
    """
    # Example coordinates (Karabük, Turkey)
    latitude = 41.2061
    longitude = 32.6204
    
    # Current date and time
    now = datetime.now()
    date = now.strftime("%Y-%m-%d")
    time = now.strftime("%H:%M:%S")
    
    # Calculate solar position
    elevation, azimuth = calculate_solar_position(latitude, longitude, date, time)
    
    print(f"Date: {date}")
    print(f"Time: {time}")
    print(f"Location: {latitude}°N, {longitude}°E")
    print(f"Sun's Elevation: {elevation:.2f}°")
    print(f"Sun's Azimuth: {azimuth:.2f}°")
    
    # Convert to servo angles
    h_angle, v_angle = get_servo_angles(elevation, azimuth)
    print(f"Horizontal Servo Angle: {h_angle:.2f}°")
    print(f"Vertical Servo Angle: {v_angle:.2f}°")

if __name__ == "__main__":
    main()