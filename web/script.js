document.addEventListener("DOMContentLoaded", function() {
    fetch("api_fetch.php")
        .then(response => response.json())
        .then(data => {
            document.getElementById("gate-status").textContent = data.status;

            const tbody = document.querySelector("#log-table tbody");
            data.logs.forEach(log => {
                const row = document.createElement("tr");
                row.innerHTML = `<td>${log.date}</td><td>${log.user}</td><td>${log.action}</td>`;
                tbody.appendChild(row);
            });
        })
        .catch(error => {
            document.getElementById("gate-status").textContent = "Erreur de chargement";
            console.error("Erreur:", error);
        });
});
