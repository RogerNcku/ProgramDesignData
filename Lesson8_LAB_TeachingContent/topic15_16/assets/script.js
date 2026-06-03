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
setupFlow('flow-fcfs',[
  'Ready queue 依照到達順序排列，最早提出 CPU request 的 process 先拿到 CPU。',
  'FCFS 是 nonpreemptive：一旦 process 取得 CPU，就會執行到結束或主動進入 waiting state。',
  '缺點是可能產生 convoy effect：如果前面有很長的 process，後面的短 process 會等很久。'
]);
setupFlow('flow-sjf',[
  'SJF 會選擇下一個 CPU burst 最短的 process 先執行。',
  '若能準確知道 burst time，SJF 可使平均等待時間最小。',
  '實際困難是 OS 通常不知道下一次 CPU burst 會有多長，因此常需要估計。'
]);
setupFlow('flow-priority',[
  'Priority scheduling 會給每個 process 一個 priority number。',
  'CPU 會分配給 priority 最高的 process；投影片中數字越小代表優先權越高。',
  '可能問題是 starvation；解法是 aging，等待越久逐漸提高 priority。'
]);
setupFlow('flow-rr',[
  'Round-Robin 會把 CPU 時間切成固定 time quantum，ready queue 採 FIFO 輪流執行。',
  '如果 process 在 quantum 內沒有結束，就被 preempted 並放回 ready queue 尾端。',
  'Quantum 太大會接近 FCFS；太小會造成太多 context switch overhead。'
]);
setupFlow('flow-timequantum',[
  'Time quantum 決定每個 process 一次最多可以使用 CPU 多久。',
  'Quantum 較小時，互動反應較快，但 context switch 次數增加。',
  'Quantum 較大時，切換成本較低，但等待與回應可能變差。'
]);
setupFlow('flow-mlq',[
  'Multilevel Queue 先把 ready queue 分成多個固定佇列，例如 system、interactive、batch、student。',
  '每個佇列可以有自己的排程演算法，例如 foreground 用 RR，background 用 FCFS。',
  '佇列之間也需要排程，例如固定優先權或 time slice 分配。'
]);
setupFlow('flow-mlfq',[
  'Multilevel Feedback Queue 允許 process 在不同佇列間移動。',
  '短工作或互動工作可留在高優先權佇列，長時間使用 CPU 的工作可能被降到較低優先權。',
  'Aging 可以避免某些 process 永遠留在低優先權佇列而 starvation。'
]);
setupFlow('flow-example-mlfq',[
  '新工作先進入最高優先權佇列 Q0，若很快完成或等待 I/O，通常保持較高回應性。',
  '若在 Q0 用完 quantum 仍未完成，就降到 Q1；若在 Q1 又用完 quantum，繼續降到 Q2。',
  '低優先權佇列通常使用 FCFS 或較長 quantum，適合 CPU-bound 或背景工作。'
]);
document.querySelectorAll('.algo-card,.gantt-piece,.priority-node,.quantum-box,.queue-lane,.queue-job,.mlfq-level,.policy-card,.metric-card').forEach(x=>x.addEventListener('click',()=>x.classList.toggle('active')));
