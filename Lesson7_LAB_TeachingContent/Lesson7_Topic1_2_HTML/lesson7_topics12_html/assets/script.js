const states={};
function initFlow(id){states[id]={i:0,timer:null}; renderFlow(id)}
function renderFlow(id){const box=document.querySelector(`[data-flow="${id}"]`); if(!box)return; const steps=[...box.querySelectorAll('.flow-step')]; const cap=box.querySelector('.flow-caption'); const s=states[id]||{i:0}; steps.forEach((el,idx)=>{el.classList.toggle('active',idx===s.i); el.classList.toggle('done',idx<s.i);}); if(cap&&steps[s.i]) cap.textContent=steps[s.i].dataset.caption || steps[s.i].textContent;}
function nextFlow(id){if(!states[id])initFlow(id); const box=document.querySelector(`[data-flow="${id}"]`); const n=box.querySelectorAll('.flow-step').length; states[id].i=Math.min(n-1,states[id].i+1); renderFlow(id)}
function prevFlow(id){if(!states[id])initFlow(id); states[id].i=Math.max(0,states[id].i-1); renderFlow(id)}
function resetFlow(id){if(!states[id])initFlow(id); clearInterval(states[id].timer); states[id].timer=null; states[id].i=0; renderFlow(id)}
function autoFlow(id){if(!states[id])initFlow(id); clearInterval(states[id].timer); const box=document.querySelector(`[data-flow="${id}"]`); const n=box.querySelectorAll('.flow-step').length; states[id].timer=setInterval(()=>{ if(states[id].i>=n-1){clearInterval(states[id].timer); states[id].timer=null;} else nextFlow(id);},1100)}
function copyCode(id){const ta=document.getElementById(id); ta.select(); document.execCommand('copy'); const b=document.querySelector(`[data-copy="${id}"]`); if(b){const old=b.textContent; b.textContent='已複製'; setTimeout(()=>b.textContent=old,1200)}}
window.addEventListener('DOMContentLoaded',()=>{document.querySelectorAll('[data-flow]').forEach(el=>initFlow(el.dataset.flow));});
