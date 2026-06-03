const flows={};
function initFlow(id,steps){flows[id]={i:0,steps,timer:null};renderFlow(id)}
function renderFlow(id){const f=flows[id]; if(!f)return; const root=document.getElementById(id); if(!root)return; const nodes=root.querySelectorAll('.node'); nodes.forEach((n,idx)=>{n.classList.toggle('active',idx===f.i);n.classList.toggle('done',idx<f.i)}); const box=root.querySelector('.stepbox'); if(box)box.innerHTML=`第 ${f.i+1} 步：${f.steps[f.i]}`; const bar=root.querySelector('.bar'); if(bar)bar.style.width=((f.i+1)/f.steps.length*100)+'%'}
function nextFlow(id){const f=flows[id]; if(!f)return; f.i=Math.min(f.i+1,f.steps.length-1); renderFlow(id)}
function prevFlow(id){const f=flows[id]; if(!f)return; f.i=Math.max(f.i-1,0); renderFlow(id)}
function resetFlow(id){const f=flows[id]; if(!f)return; clearInterval(f.timer); f.i=0; renderFlow(id)}
function playFlow(id){const f=flows[id]; if(!f)return; clearInterval(f.timer); f.timer=setInterval(()=>{ if(f.i>=f.steps.length-1){clearInterval(f.timer);return;} f.i++; renderFlow(id)},1100)}
function copyCode(id){const el=document.getElementById(id); el.select(); document.execCommand('copy'); toast('程式碼已複製，可以貼到線上編輯器執行。')}
function toast(msg){let t=document.querySelector('.toast'); if(!t){t=document.createElement('div'); t.className='toast'; document.body.appendChild(t)} t.textContent=msg; t.classList.add('show'); setTimeout(()=>t.classList.remove('show'),2300)}
function downloadCode(id,filename){const text=document.getElementById(id).value; const blob=new Blob([text],{type:'text/plain'}); const a=document.createElement('a'); a.href=URL.createObjectURL(blob); a.download=filename; a.click(); URL.revokeObjectURL(a.href)}
