const flows={
  "flow-arch":["先從單一 CPU 架構理解：所有指令主要由一個處理器依序處理。","多處理器系統加入多顆 CPU，共享記憶體與匯流排，能提升 throughput。","多核心設計把多個核心放在同一晶片上，每個 core 有自己的 registers 與 local cache。"],
  "flow-os-structure":["多程式設計把多個 Job 放進記憶體，避免 CPU 閒置。","OS 從記憶體中的多個程式挑選一個交給 CPU 執行。","Time sharing 透過快速切換，讓多個使用者或程式看起來像同時互動。","當程式等待 I/O 或時間片用完，OS 會切換到下一個 ready process。"]
};
document.querySelectorAll('.flowbox').forEach(box=>{
  let steps=[...box.querySelectorAll('.flow-step')]; let caption=box.querySelector('.flow-caption'); let i=0; let texts=flows[box.id]||[];
  function render(){steps.forEach((s,idx)=>{s.classList.toggle('active',idx===i);s.classList.toggle('done',idx<i)}); if(caption) caption.textContent=texts[i]||'';
    if(box.id==='flow-arch'){document.querySelectorAll('.arch-card').forEach((c,idx)=>c.classList.toggle('active',idx===i));}
    if(box.id==='flow-os-structure'){document.querySelectorAll('.job,.slice').forEach((c,idx)=>c.classList.toggle('active',idx===i));}
  }
  render();
  box.querySelector('.next')?.addEventListener('click',()=>{i=(i+1)%steps.length;render();});
  box.querySelector('.prev')?.addEventListener('click',()=>{i=(i-1+steps.length)%steps.length;render();});
  box.querySelector('.reset')?.addEventListener('click',()=>{i=0;render();});
  setInterval(()=>{i=(i+1)%steps.length;render();},3800);
});
