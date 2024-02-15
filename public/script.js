function calculate() {
    const usageTime = parseFloat(document.getElementById('usageTime').value);
    const appliancePower = parseFloat(document.getElementById('appliancePower').value);
    const state = document.getElementById('state').value;
    const day = document.getElementById('day').value;


    if (isNaN(usageTime) || isNaN(appliancePower) || state === ''|| day === '') {
        alert('Por favor, preencha todos os campos corretamente.');
        return;
    }

    // Enviar dados para o backend
    fetch('/calculate', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({
            usageTime,
            appliancePower, 
            state,
            day,    
        }),
    })
    .then(response => response.json())
    .then(data => {
        // Atualizar a exibição dos resultados na página
        document.getElementById('monthlyCost').innerText = `Custo Mensal Médio: R$ ${data.monthlyCost.toFixed(2)}`;

        document.getElementById('results-container').style.display = 'block';
    })
    .catch(error => {
        console.error('Erro na requisição:', error);
    });
}
