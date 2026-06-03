
const flowStates = {};
function initFlow(id, texts){const area=document.getElementById(id);if(!area)return;flowStates[id]={i:0,texts:texts||[]};showFlow(id)}
function showFlow(id){const area=document.getElementById(id), st=flowStates[id];if(!area||!st)return;const nodes=[...area.querySelectorAll('.flow .node')];nodes.forEach((n,k)=>n.classList.toggle('active',k===st.i));const box=area.querySelector('.stepbox');if(box)box.textContent=st.texts[st.i]||'';const bar=area.querySelector('.bar');if(bar)bar.style.width=nodes.length?((st.i+1)/nodes.length*100)+'%':'0'}
function nextFlow(id){const st=flowStates[id], n=document.querySelectorAll('#'+id+' .flow .node').length;if(!st||!n)return;st.i=(st.i+1)%n;showFlow(id)}
function prevFlow(id){const st=flowStates[id], n=document.querySelectorAll('#'+id+' .flow .node').length;if(!st||!n)return;st.i=(st.i-1+n)%n;showFlow(id)}
function resetFlow(id){if(flowStates[id]){flowStates[id].i=0;showFlow(id)}}
function playFlow(id){const n=document.querySelectorAll('#'+id+' .flow .node').length;if(!n)return;let c=0;resetFlow(id);const t=setInterval(()=>{nextFlow(id); if(++c>=n-1)clearInterval(t)},900)}
const tableStates = {};
function initTable(id, notes){const area=document.getElementById(id);if(!area)return;tableStates[id]={i:0,notes:notes||[]};showTable(id)}
function showTable(id){const area=document.getElementById(id), st=tableStates[id];if(!area||!st)return;const rows=[...area.querySelectorAll('tbody tr')];rows.forEach((r,k)=>r.classList.toggle('active',k===st.i));const note=area.querySelector('.table-note');if(note)note.textContent=st.notes[st.i]||'';const bar=area.querySelector('.bar');if(bar)bar.style.width=rows.length?((st.i+1)/rows.length*100)+'%':'0';rows[st.i]?.scrollIntoView({block:'nearest',behavior:'smooth'})}
function nextTable(id){const st=tableStates[id], n=document.querySelectorAll('#'+id+' tbody tr').length;if(!st||!n)return;st.i=(st.i+1)%n;showTable(id)}
function prevTable(id){const st=tableStates[id], n=document.querySelectorAll('#'+id+' tbody tr').length;if(!st||!n)return;st.i=(st.i-1+n)%n;showTable(id)}
function resetTable(id){if(tableStates[id]){tableStates[id].i=0;showTable(id)}}
function playTable(id){const n=document.querySelectorAll('#'+id+' tbody tr').length;if(!n)return;let c=0;resetTable(id);const t=setInterval(()=>{nextTable(id); if(++c>=n-1)clearInterval(t)},850)}
function copyCode(id){const el=document.getElementById(id);if(!el)return;el.select();document.execCommand('copy');alert('程式碼已複製');}
function downloadCode(id, filename){const el=document.getElementById(id);if(!el)return;const blob=new Blob([el.value],{type:'text/plain;charset=utf-8'});const a=document.createElement('a');a.href=URL.createObjectURL(blob);a.download=filename||'code.c';a.click();URL.revokeObjectURL(a.href)}
