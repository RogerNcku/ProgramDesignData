const flowState={};
function initFlow(id,steps){flowState[id]={i:0,steps,timer:null};updateFlow(id)}
function updateFlow(id){const s=flowState[id];if(!s)return;const root=document.getElementById(id);const nodes=root.querySelectorAll('.node');nodes.forEach((n,k)=>n.classList.toggle('active',k<=s.i));const bar=root.querySelector('.bar');if(bar)bar.style.width=((s.i+1)/nodes.length*100)+'%';const box=root.querySelector('.stepbox');if(box)box.innerHTML='第 '+(s.i+1)+' 步：'+s.steps[s.i];}
function nextFlow(id){const s=flowState[id];if(!s)return;const root=document.getElementById(id);const max=root.querySelectorAll('.node').length-1;s.i=Math.min(max,s.i+1);updateFlow(id)}
function prevFlow(id){const s=flowState[id];if(!s)return;s.i=Math.max(0,s.i-1);updateFlow(id)}
function resetFlow(id){const s=flowState[id];if(!s)return;clearInterval(s.timer);s.timer=null;s.i=0;updateFlow(id)}
function playFlow(id){const s=flowState[id];if(!s)return;clearInterval(s.timer);s.timer=setInterval(()=>{const max=document.getElementById(id).querySelectorAll('.node').length-1;if(s.i>=max){clearInterval(s.timer);s.timer=null}else{nextFlow(id)}},950)}
const tableState={};
function initTable(id){tableState[id]=0;showRows(id)}
function showRows(id){const rows=document.querySelectorAll('#'+id+' tbody tr');rows.forEach((r,i)=>r.classList.toggle('show',i<=tableState[id]));}
function nextRow(id){const rows=document.querySelectorAll('#'+id+' tbody tr');tableState[id]=Math.min(rows.length-1,(tableState[id]||0)+1);showRows(id)}
function prevRow(id){tableState[id]=Math.max(0,(tableState[id]||0)-1);showRows(id)}
function resetTable(id){tableState[id]=0;showRows(id)}
function copyCode(id){const t=document.getElementById(id);t.select();document.execCommand('copy');alert('程式碼已複製，可以貼到線上編輯器執行。')}
