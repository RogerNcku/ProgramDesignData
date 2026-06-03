function setupFlow(id,captions){
  const box=document.getElementById(id); if(!box)return;
  const steps=[...box.querySelectorAll('.flow-step')]; const cap=box.querySelector('.flow-caption');
  let idx=0;
  function render(){steps.forEach((s,i)=>{s.classList.toggle('active',i===idx);s.classList.toggle('done',i<idx)}); if(cap)cap.textContent=captions[idx]||'';}
  box.querySelector('.next')?.addEventListener('click',()=>{idx=Math.min(idx+1,steps.length-1);render();});
  box.querySelector('.prev')?.addEventListener('click',()=>{idx=Math.max(idx-1,0);render();});
  box.querySelector('.reset')?.addEventListener('click',()=>{idx=0;render();});
  render();
}
setupFlow('flow-process',[
  '程式本身只是放在磁碟或記憶體中的被動內容，尚未真正執行。',
  '當程式開始執行，就成為 process；process 需要 CPU、memory、I/O、files 等資源。',
  '行程結束後，作業系統要回收可重複使用的資源，避免資源被浪費。'
]);
setupFlow('flow-memory',[
  '所有資料在處理前必須先進入記憶體。',
  '所有指令必須在記憶體中，CPU 才能執行。',
  'Memory management 會決定哪些行程與資料要留在記憶體、何時移入或移出。',
  '當需要時，OS 會配置或釋放記憶體空間。'
]);
setupFlow('flow-multi',[
  '單一程式環境中，記憶體大多只有 OS 和一個 program。',
  '多程式環境中，記憶體同時保留多個 program。',
  'CPU 可以在多個 program 之間切換，所以當某個程式等待 I/O 時，CPU 可先執行另一個程式。'
]);
setupFlow('flow-partition',[
  'Program 1 被放入一段連續的記憶體區塊，CPU 開始執行 Program 1。',
  '當 OS 排程切換時，CPU 改為執行 Program 2，但兩個程式仍各自佔有連續的記憶體分割區。'
]);

document.querySelectorAll('.mem-block,.part').forEach(x=>x.addEventListener('click',()=>x.classList.toggle('active')));
