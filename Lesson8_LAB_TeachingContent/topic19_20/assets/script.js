const captions={
 'flow-starvation':['資源可以被多個 process 競爭，低優先權或一直搶不到資源的 process 可能長期等待。','系統一直把資源分給其他 process，某個 process 雖然不是死結，卻一直無法完成。','常見改善方式是 aging：等待越久，優先權逐漸提高。'],
 'flow-deadlock':['Process A 先持有一部分資源，同時還需要另一個資源。','Process B 也持有資源，並等待 A 手上的資源。','彼此互相等待，沒有任何一方能繼續執行，就形成 deadlock。'],
 'flow-rag':['圓形節點代表 process，方形節點代表 resource type。','Process → Resource 表示 request edge，也就是 process 正在要求資源。','Resource → Process 表示 assignment edge，也就是資源已經分配給 process。'],
 'flow-cycle':['如果資源配置圖沒有 cycle，表示沒有 deadlock。','如果有 cycle，而且每種 resource type 只有一個 instance，就一定 deadlock。','如果有 cycle，但某些 resource type 有多個 instance，則只是可能 deadlock。'],
 'flow-conditions':['第一個條件是互斥：某些資源同一時間只能給一個 process 使用。','第二個條件是持有並等待：process 已拿到一些資源，同時還在等其他資源。','第三個條件是不可搶奪：資源不能被系統硬搶回，只能由持有者主動釋放。','第四個條件是循環等待：P0 等 P1、P1 等 P2，最後又有人等回 P0。'],
 'flow-prevent':['破壞 Mutual Exclusion：盡量使用可共享資源，但不是所有資源都能共享。','破壞 Hold and Wait：要求 process 一次拿齊資源，或拿不到就不要占住資源。','破壞 No Preemption：允許系統在必要時收回某些資源。','破壞 Circular Wait：規定資源申請順序，避免形成環狀等待。']
};
document.querySelectorAll('.flowbox').forEach(box=>{
  const steps=[...box.querySelectorAll('.flow-step')]; const cap=box.querySelector('.flow-caption'); let idx=0;
  const update=()=>{steps.forEach((s,i)=>{s.classList.toggle('active',i===idx);s.classList.toggle('done',i<idx)}); if(cap) cap.textContent=(captions[box.id]||[])[idx]||steps[idx]?.textContent||'';};
  box.querySelector('.next')?.addEventListener('click',()=>{idx=Math.min(idx+1,steps.length-1);update()});
  box.querySelector('.prev')?.addEventListener('click',()=>{idx=Math.max(idx-1,0);update()});
  box.querySelector('.reset')?.addEventListener('click',()=>{idx=0;update()}); update();
});
