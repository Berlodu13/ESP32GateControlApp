<?php
require 'db_connect.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $badge_id = $_POST['badge_id'] ?? '';

    $stmt = $pdo->prepare("SELECT active FROM authorized_badges WHERE badge_id = ?");
    $stmt->execute([$badge_id]);
    $badge = $stmt->fetch();

    $access_granted = $badge && $badge['active'] ? 1 : 0;

    $log = $pdo->prepare("INSERT INTO access_log (badge_id, access_granted) VALUES (?, ?)");
    $log->execute([$badge_id, $access_granted]);

    echo json_encode(['access_granted' => $access_granted]);
}
?>
