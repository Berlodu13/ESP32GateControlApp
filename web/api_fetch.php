<?php
header('Content-Type: application/json');

$host = 'localhost';
$db = 'esp32gate';
$user = 'root';
$pass = '';

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) {
    echo json_encode(["status" => "Erreur de connexion", "logs" => []]);
    exit;
}

$status_result = $conn->query("SELECT status FROM gate_status ORDER BY timestamp DESC LIMIT 1");
$status = $status_result->fetch_assoc()["status"];

$logs_result = $conn->query("SELECT date, user, action FROM access_logs ORDER BY date DESC LIMIT 20");
$logs = [];
while ($row = $logs_result->fetch_assoc()) {
    $logs[] = $row;
}

echo json_encode(["status" => $status, "logs" => $logs]);
$conn->close();
?>
