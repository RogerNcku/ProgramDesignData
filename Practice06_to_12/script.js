
let states = {};
function initRunner(id, lines, output){
  states[id] = {idx:0, lines:lines, output:output};
  renderRunner(id);
}
function renderRunner(id){
  const st = states[id];
  const code = document.getElementById(id + "_code");
  const out = document.getElementById(id + "_out");
  let html = "";
  for(let i=0;i<st.lines.length;i++){
    const safe = st.lines[i].replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;");
    html += `<div class="${i===st.idx-1?'highlight':''}"><span class="note">${String(i+1).padStart(2,'0')}</span> ${safe}</div>`;
  }
  code.innerHTML = html;
  const ratio = st.lines.length===0 ? 1 : st.idx / st.lines.length;
  const n = Math.floor(st.output.length * ratio);
  out.textContent = st.output.slice(0,n);
}
function stepRunner(id){
  const st = states[id];
  if(st.idx < st.lines.length) st.idx++;
  renderRunner(id);
}
function resetRunner(id){
  states[id].idx = 0;
  renderRunner(id);
}
function playRunner(id){
  resetRunner(id);
  const timer = setInterval(()=>{
    stepRunner(id);
    if(states[id].idx >= states[id].lines.length) clearInterval(timer);
  }, 260);
}
