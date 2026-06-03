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
setupFlow('flow-paging',[
  '程式的 logical memory 先被切成固定大小的 page，例如 Page 1、Page 2。',
  '實體記憶體 physical memory 也被切成同樣大小的 frame。',
  'Page table 負責記錄每個 page 被放到哪一個 frame，因此 page 不必連續放置。'
]);
setupFlow('flow-demand',[
  '程式一開始不需要全部載入，只要先載入目前會用到的部分。',
  '當 CPU 執行到尚未在記憶體中的 page 或 segment，就會向磁碟要求載入。',
  'OS 將需要的部分放進 physical memory，再讓程式繼續執行。'
]);
setupFlow('flow-storage',[
  'OS 把檔案與目錄抽象化，使用者看到的是 file 與 folder，不需要直接面對磁碟細節。',
  'File-system management 會建立、刪除、讀寫檔案與目錄，並把檔案對應到儲存空間。',
  'OS 也會進行備份與非揮發性儲存管理，確保關機後資料仍能保存。'
]);
setupFlow('flow-protection',[
  '使用者或行程提出存取要求，例如讀取檔案、使用 I/O 或存取記憶體。',
  'OS 根據 user ID、權限、process 身分與存取控制規則判斷是否允許。',
  '合法的要求被允許；不合法或危險的要求會被拒絕，以保護系統與資料。'
]);
document.querySelectorAll('.page-row,.frame-row,.seg-item,.file,.folder,.user-card,.resource-card').forEach(x=>x.addEventListener('click',()=>x.classList.toggle('active')));
