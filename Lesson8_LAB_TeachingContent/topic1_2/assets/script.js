
function setupFlow(id, captions){
  const box=document.getElementById(id); if(!box) return;
  const steps=[...box.querySelectorAll('.flow-step')];
  const cap=box.querySelector('.flow-caption'); let i=0;
  function paint(){steps.forEach((s,idx)=>{s.classList.toggle('active',idx===i);s.classList.toggle('done',idx<i)}); if(cap) cap.textContent=captions[i]||'';}
  box.querySelector('.next')?.addEventListener('click',()=>{i=(i+1)%steps.length;paint();});
  box.querySelector('.prev')?.addEventListener('click',()=>{i=(i-1+steps.length)%steps.length;paint();});
  box.querySelector('.reset')?.addEventListener('click',()=>{i=0;paint();});
  paint();
}
window.addEventListener('DOMContentLoaded',()=>{
 setupFlow('flow-os',['使用者提出需求，例如開啟程式、讀取檔案或輸入資料。','應用程式把需求交給作業系統處理，而不是直接碰硬體。','作業系統負責管理 CPU、記憶體、I/O、檔案與安全權限。','硬體依照作業系統的控制執行實際運算與資料存取。']);
 setupFlow('flow-boot',['電腦開機或重新啟動後，CPU 先從 ROM / EPROM 執行 firmware。','Bootstrap program 初始化系統必要硬體與核心資料結構。','Bootstrap 將作業系統核心載入主記憶體。','控制權交給作業系統，系統開始提供程式執行與資源管理。']);
});
