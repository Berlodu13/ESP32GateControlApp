CREATE DATABASE IF NOT EXISTS gate_control;
USE gate_control;

CREATE TABLE IF NOT EXISTS access_log (
    id INT AUTO_INCREMENT PRIMARY KEY,
    badge_id VARCHAR(50) NOT NULL,
    access_time DATETIME DEFAULT CURRENT_TIMESTAMP,
    access_granted BOOLEAN DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS authorized_badges (
    badge_id VARCHAR(50) PRIMARY KEY,
    owner_name VARCHAR(100),
    active BOOLEAN DEFAULT TRUE
);
