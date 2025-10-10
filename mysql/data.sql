USE gate_control;

INSERT INTO authorized_badges (badge_id, owner_name, active) VALUES
('ABC123', 'Laurent Dupont', TRUE),
('XYZ789', 'Marie Curie', TRUE);

INSERT INTO access_log (badge_id, access_granted) VALUES
('ABC123', TRUE),
('XYZ789', FALSE);
