document.addEventListener("keydown", (event) => {
    const playerRect = player.getBoundingClientRect();
    const gameAreaRect = document.getElementById("game-area").getBoundingClientRect();

    if (event.key === "ArrowUp" && playerRect.top > gameAreaRect.top) {
        player.style.top = `${player.offsetTop - 20}px`;
    } else if (event.key === "ArrowDown" && playerRect.bottom < gameAreaRect.bottom) {
        player.style.top = `${player.offsetTop + 20}px`;
    } else if (event.key === "ArrowLeft" && playerRect.left > gameAreaRect.left) {
        player.style.left = `${player.offsetLeft - 20}px`;
    } else if (event.key === "ArrowRight" && playerRect.right < gameAreaRect.right) {
        player.style.left = `${player.offsetLeft + 20}px`;
    }
});

function moveEnemies() {
    enemies.forEach((enemy) => {
        const enemyRect = enemy.getBoundingClientRect();
        const gameAreaRect = document.getElementById("game-area").getBoundingClientRect();

        if (enemyRect.top >= gameAreaRect.bottom) {
            resetEnemy(enemy);
        } else {
            enemy.style.top = `${enemy.offsetTop + enemySpeed}px`;
        }
    });

    requestAnimationFrame(moveEnemies);
}

function resetEnemy(enemy) {
    enemy.style.top = "0px";
    enemy.style.left = `${Math.random() * 90}vw`;
}

function checkCollision() {
    const playerRect = player.getBoundingClientRect();

    enemies.forEach((enemy) => {
        const enemyRect = enemy.getBoundingClientRect();

        if (
            playerRect.left < enemyRect.right &&
            playerRect.right > enemyRect.left &&
            playerRect.top < enemyRect.bottom &&
            playerRect.bottom > enemyRect.top
        ) {
            endGame();
        }
    });

    requestAnimationFrame(checkCollision);
}

function endGame() {
    alert(`Game Over! You survived for ${timeElapsed} seconds.`);
    location.reload();
}

let enemySpeed = 2;
setInterval(() => {
    enemySpeed += 1;
}, 5000);

let timeElapsed = 0;
setInterval(() => {
    timeElapsed++;
    document.getElementById("timer").textContent = `Time: ${timeElapsed} seconds`;
}, 1000);
