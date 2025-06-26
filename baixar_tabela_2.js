//Digite allow pasting antes
const tabela = document.getElementById("lrTableView");
const headtabela = tabela.getElementsByTagName("thead")[0];
const headCelulas = headtabela.getElementsByTagName("tr")[2].getElementsByTagName("th");

const ACTION_GOTO_LIST = [];
for (let i = 0; i < headCelulas.length; i++) {
  ACTION_GOTO_LIST.push(headCelulas[i].textContent.trim());
}

const bodyLinhas = tabela.getElementsByTagName("tbody")[0].getElementsByTagName("tr");
const STATE_ACTION_GOTO_LINES = [];

for (let j = 0; j < bodyLinhas.length; j++) {
  const linha = bodyLinhas[j];
  const celulasLinha = linha.getElementsByTagName("td");
  for (let k = 1; k < celulasLinha.length; k++) {
    let valueCelula = celulasLinha[k].textContent;
    if (valueCelula === "\u00A0") continue;

    // Remove ambiguidade: pega só antes de "/" e dá trim
    const primeiraTransicao = valueCelula.split('/')[0].trim();
    if (!primeiraTransicao) continue;

    const estado = j;
    const simbolo = ACTION_GOTO_LIST[k - 1];
    STATE_ACTION_GOTO_LINES.push(`${estado} ${simbolo} ${primeiraTransicao}`);
  }
}

const TABLE_LINEARIZED = STATE_ACTION_GOTO_LINES.join("\n");
console.log(TABLE_LINEARIZED);

// faz download em arquivo .conf
const blob = new Blob([TABLE_LINEARIZED], { type: "text/plain" });
const link = document.createElement("a");
link.href = URL.createObjectURL(blob);
link.download = "tabela_lr1.conf";
document.body.appendChild(link);
link.click();
document.body.removeChild(link);