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

setupFlow('flow-process-state',[
  'New：行程剛被建立，作業系統準備把它放入可執行的管理流程。',
  'Ready：行程已經在記憶體中，等待 CPU scheduler 分配 CPU。',
  'Running：行程取得 CPU，正在執行指令。',
  'Waiting：行程等待 I/O 或某個事件完成，暫時不能使用 CPU。',
  'Terminated：行程執行完畢，作業系統回收相關資源。'
]);
setupFlow('flow-pcb',[
  '當行程存在時，OS 需要用 PCB 記錄它的狀態。',
  'PCB 會保存 program counter 與 CPU registers，讓行程被切走後還能恢復。',
  'PCB 也保存 scheduling、memory、accounting、I/O 等管理資訊。'
]);
setupFlow('flow-scheduler',[
  'Long-term scheduler 決定哪些 job 可以進入記憶體與 ready queue，控制 multiprogramming 程度。',
  'Short-term scheduler 又稱 CPU scheduler，快速且頻繁地從 ready queue 挑選下一個行程執行。',
  'Medium-term scheduler 會把部分行程 swap out / swap in，以調整記憶體與 CPU 負載。'
]);
setupFlow('flow-context-switch',[
  'CPU 從 Process 0 執行中收到 interrupt 或系統事件。',
  'OS 將 Process 0 的狀態存入它的 PCB，例如 PC、registers、狀態等。',
  'OS 從 Process 1 的 PCB 載入狀態，CPU 接著執行 Process 1。'
]);
document.querySelectorAll('.state-node,.mem-block,.pcb-row,.scheduler-card,.proc-box,.queue-item').forEach(x=>x.addEventListener('click',()=>x.classList.toggle('active')));
