/*
  Lesson 6 互動網頁共用腳本（中文註解版）
  功能：
  1. 控制流程圖動畫上一頁、下一頁、自動播放、重設。
  2. 控制表格列高亮動畫。
  3. 補齊各主題頁面使用到的互動函式，避免按鈕無反應。
  4. 修正 copyCode 可同時支援 <textarea> 與 <code>。
*/

// 使用 var 而不是 const，避免同一頁不小心重複載入 script 時造成 redeclare 錯誤。
var flowStates = window.flowStates || {};
var tableStates = window.tableStates || {};
window.flowStates = flowStates;
window.tableStates = tableStates;

// 初始化流程圖。texts 參數用於新版節點式流程動畫；沒有 texts 則使用 data-flow 流程盒。
function initFlow(id, texts){
  if (texts){
    var area = document.getElementById(id);
    if(!area) return;
    flowStates[id] = {mode:'new', i:0, texts:texts || []};
    showFlow(id);
    return;
  }
  var box = document.querySelector('[data-flow="' + id + '"]');
  if(!box) return;
  if(flowStates[id] === undefined || typeof flowStates[id] !== 'number') flowStates[id] = 0;
  var steps = Array.from(box.querySelectorAll('.flow-step'));
  steps.forEach(function(step, i){
    step.classList.toggle('done', i < flowStates[id]);
    step.classList.toggle('active', i === flowStates[id]);
  });
  var cap = box.querySelector('.flow-caption');
  if(cap && steps[flowStates[id]]) cap.textContent = steps[flowStates[id]].dataset.caption || steps[flowStates[id]].textContent;
}

// 顯示新版節點式流程動畫的目前步驟。
function showFlow(id){
  var area = document.getElementById(id);
  var st = flowStates[id];
  if(!area || !st || st.mode !== 'new') return;
  var nodes = Array.from(area.querySelectorAll('.flow .node'));
  nodes.forEach(function(node, k){ node.classList.toggle('active', k === st.i); });
  var box = area.querySelector('.stepbox');
  if(box) box.textContent = st.texts[st.i] || '';
  var bar = area.querySelector('.bar');
  if(bar) bar.style.width = nodes.length ? ((st.i + 1) / nodes.length * 100) + '%' : '0';
}

// 流程圖下一步。
function nextFlow(id){
  var st = flowStates[id];
  if(st && st.mode === 'new'){
    var n = document.querySelectorAll('#' + id + ' .flow .node').length;
    if(!n) return;
    st.i = (st.i + 1) % n;
    showFlow(id);
    return;
  }
  var box = document.querySelector('[data-flow="' + id + '"]');
  if(!box) return;
  var steps = Array.from(box.querySelectorAll('.flow-step'));
  flowStates[id] = Math.min((flowStates[id] || 0) + 1, Math.max(steps.length - 1, 0));
  initFlow(id);
}

// 流程圖上一步。
function prevFlow(id){
  var st = flowStates[id];
  if(st && st.mode === 'new'){
    var n = document.querySelectorAll('#' + id + ' .flow .node').length;
    if(!n) return;
    st.i = (st.i - 1 + n) % n;
    showFlow(id);
    return;
  }
  flowStates[id] = Math.max((flowStates[id] || 0) - 1, 0);
  initFlow(id);
}

// 流程圖重新開始。
function resetFlow(id){
  var st = flowStates[id];
  if(st && st.mode === 'new'){
    st.i = 0;
    showFlow(id);
    return;
  }
  flowStates[id] = 0;
  initFlow(id);
}

// 流程圖自動播放。
function playFlow(id){
  var st = flowStates[id];
  if(st && st.mode === 'new'){
    var n = document.querySelectorAll('#' + id + ' .flow .node').length;
    if(!n) return;
    var c = 0;
    resetFlow(id);
    var t = setInterval(function(){
      nextFlow(id);
      if(++c >= n - 1) clearInterval(t);
    }, 900);
    return;
  }
  resetFlow(id);
  var box = document.querySelector('[data-flow="' + id + '"]');
  if(!box) return;
  var steps = Array.from(box.querySelectorAll('.flow-step'));
  var i = 0;
  var timer = setInterval(function(){
    i++;
    flowStates[id] = i;
    initFlow(id);
    if(i >= steps.length - 1) clearInterval(timer);
  }, 900);
}
function autoFlow(id){ playFlow(id); }

// 初始化表格動畫。
function initTable(id, notes){
  var area = document.getElementById(id);
  if(!area) return;
  tableStates[id] = {i:0, notes:notes || []};
  showTable(id);
}
function showTable(id){
  var area = document.getElementById(id), st = tableStates[id];
  if(!area || !st) return;
  var rows = Array.from(area.querySelectorAll('tbody tr'));
  rows.forEach(function(row, k){ row.classList.toggle('active', k === st.i); });
  var note = area.querySelector('.table-note');
  if(note) note.textContent = st.notes[st.i] || '';
  var bar = area.querySelector('.bar');
  if(bar) bar.style.width = rows.length ? ((st.i + 1) / rows.length * 100) + '%' : '0';
  if(rows[st.i]) rows[st.i].scrollIntoView({block:'nearest', behavior:'smooth'});
}
function nextTable(id){ var st = tableStates[id], n = document.querySelectorAll('#' + id + ' tbody tr').length; if(!st || !n) return; st.i = (st.i + 1) % n; showTable(id); }
function prevTable(id){ var st = tableStates[id], n = document.querySelectorAll('#' + id + ' tbody tr').length; if(!st || !n) return; st.i = (st.i - 1 + n) % n; showTable(id); }
function resetTable(id){ if(tableStates[id]){ tableStates[id].i = 0; showTable(id); } }
function playTable(id){ var n = document.querySelectorAll('#' + id + ' tbody tr').length; if(!n) return; var c = 0; resetTable(id); var t = setInterval(function(){ nextTable(id); if(++c >= n - 1) clearInterval(t); }, 850); }

// 樹的基本概念：點選 Root、Parent、Children、Leaf、Subtree 時高亮節點並顯示說明。
function highlightTree(name){
  document.querySelectorAll('.node').forEach(function(n){ n.classList.remove('active'); });
  document.querySelectorAll('[data-node~="' + name + '"]').forEach(function(n){ n.classList.add('active'); });
  var text = {
    root:'Root 是最上方的節點，是整棵樹的起點。',
    parent:'Parent 是某些子樹的上一層節點；例如 A 是 B、C 的 parent。',
    child:'Children 是某節點往下一層連出去的節點；例如 B、C 是 A 的 children。',
    leaf:'Leaf 是 degree 為 0 的節點，也就是沒有孩子的節點。',
    subtree:'Subtree 是從某個節點往下形成的一棵小樹。'
  };
  var el = document.getElementById('treeText');
  if(el) el.textContent = text[name] || '';
}

// 二元樹概念互動：高亮 root、left subtree、right subtree、leaf。
function binaryFocus(name){
  document.querySelectorAll('[data-bnode]').forEach(function(n){ n.classList.remove('active'); });
  document.querySelectorAll('[data-bnode~="' + name + '"]').forEach(function(n){ n.classList.add('active'); });
  var text = {
    root:'Root 是二元樹最上面的節點，所有遞迴操作通常都從 root 開始。',
    left:'Left subtree 是 root 左邊的子樹；二元樹會明確區分左邊與右邊。',
    right:'Right subtree 是 root 右邊的子樹；就算資料相同，左右位置不同也算不同樹。',
    leaf:'Leaf 是沒有左孩子也沒有右孩子的節點，是遞迴走到底的位置。'
  };
  var el = document.getElementById('binaryText');
  if(el) el.textContent = text[name] || '';
}

// 陣列表示法互動：點選 index 後顯示 parent、left child、right child 公式結果。
function arrayFocus(i){
  document.querySelectorAll('.cell').forEach(function(c){ c.classList.remove('active'); });
  document.querySelectorAll('[data-index="' + i + '"]').forEach(function(c){ c.classList.add('active'); });
  var parent = i === 1 ? '無，index 1 是 root' : Math.floor(i / 2);
  var left = (2 * i <= 7) ? 2 * i : '無';
  var right = (2 * i + 1 <= 7) ? 2 * i + 1 : '無';
  var el = document.getElementById('arrayText') || document.querySelector('.array-note');
  if(el) el.textContent = '目前 index ' + i + '：parent = ' + parent + '，left child = ' + left + '，right child = ' + right + '。';
}

// 表示法切換：顯示 arrayPanel 或 linkedPanel。
function showRep(panelId){
  document.querySelectorAll('.rep-panel').forEach(function(p){ p.classList.remove('active'); p.style.display = 'none'; });
  var panel = document.getElementById(panelId);
  if(panel){ panel.classList.add('active'); panel.style.display = 'block'; }
}

// Binary tree traversal 動畫：依照走訪順序依序高亮 SVG 節點。
var traversalOrders = {
  inorder: ['D','B','E','A','C','F'],
  preorder: ['A','B','D','E','C','F'],
  postorder: ['D','E','B','F','C','A']
};
function clearTraversal(){
  document.querySelectorAll('.tree-svg circle').forEach(function(c){ c.classList.remove('active','visit'); });
  var out = document.getElementById('travOutput');
  if(out) out.innerHTML = '';
}
function runTraversal(type){
  clearTraversal();
  var order = traversalOrders[type] || [];
  var out = document.getElementById('travOutput');
  var i = 0;
  var timer = setInterval(function(){
    if(i >= order.length){ clearInterval(timer); return; }
    var name = order[i];
    var node = document.getElementById('svg' + name);
    if(node){ node.classList.add('visit'); setTimeout(function(){ node.classList.remove('active'); }, 500); }
    if(out) out.innerHTML += '<span>' + name + '</span>';
    i++;
  }, 650);
}

// BST 搜尋互動：主題 6 使用 bst 開頭的節點 id。
function resetBST(){
  document.querySelectorAll('[id^="bst"]').forEach(function(n){ n.classList.remove('hit','path','active'); });
  var log = document.getElementById('bstLog');
  if(log) log.textContent = '選一個數字開始搜尋。';
}
function searchBST(target){
  resetBST();
  var paths = {
    1:[7,3,2,1],
    8:[7,14,10,8],
    15:[7,14,10,16],
    16:[7,14,10,16]
  };
  var path = paths[target] || [7];
  var log = document.getElementById('bstLog');
  var i = 0;
  var timer = setInterval(function(){
    if(i >= path.length){
      if(log) log.textContent = '搜尋 ' + target + '：走訪路徑 ' + path.join(' → ') + (target === 15 ? '，最後往空節點，所以 NOT FOUND。' : '，找到目標。');
      clearInterval(timer);
      return;
    }
    var el = document.getElementById('bst' + path[i]);
    if(el) el.classList.add(i === path.length - 1 && target !== 15 ? 'hit' : 'path');
    i++;
  }, 500);
}

// 建立 BST 動畫：依照投影片常見資料序列逐步顯示插入結果。
var buildSeq = [7,3,14,2,4,10,16,1,8];
var buildIndex = 0;
function resetBuild(){
  buildIndex = 0;
  document.querySelectorAll('[id^="build"]').forEach(function(n){ n.classList.remove('hit','path','active'); n.style.opacity = '0.18'; });
  var log = document.getElementById('buildLog');
  if(log) log.textContent = '按「下一步」開始一筆一筆建立 BST。';
}
function stepBuild(){
  if(buildIndex >= buildSeq.length) return;
  var value = buildSeq[buildIndex++];
  var el = document.getElementById('build' + value);
  if(el){ el.style.opacity = '1'; el.classList.add('hit'); setTimeout(function(){ el.classList.remove('hit'); el.classList.add('path'); }, 450); }
  document.querySelectorAll('.insert-item').forEach(function(item, idx){ item.classList.toggle('done', idx < buildIndex); });
  var log = document.getElementById('buildLog');
  if(log) log.textContent = '第 ' + buildIndex + ' 步：插入 ' + value + '。已插入序列：' + buildSeq.slice(0, buildIndex).join(', ') + '。';
}
function autoBuild(){
  resetBuild();
  var timer = setInterval(function(){
    stepBuild();
    if(buildIndex >= buildSeq.length) clearInterval(timer);
  }, 650);
}

// BST 刪除案例切換：顯示 leaf、one child、two children 三種情況。
function showDeleteCase(n){
  document.querySelectorAll('.delete-case').forEach(function(c){ c.style.display = 'none'; });
  document.querySelectorAll('.delete-tab').forEach(function(b){ b.classList.remove('primary'); });
  var box = document.getElementById('delcase' + n);
  var btn = document.getElementById('delbtn' + n);
  if(box) box.style.display = 'grid';
  if(btn) btn.classList.add('primary');
}

// BST sort 動畫：Inorder 輸出會是由小到大。
var bstSortOrder = [1,2,3,4,7,8,9,10,14,16];
var bstSortIndex = 0;
function resetBstSort(){
  bstSortIndex = 0;
  var out = document.getElementById('bstSortOut');
  if(out) out.innerHTML = '';
}
function nextBstSort(){
  var out = document.getElementById('bstSortOut');
  if(!out || bstSortIndex >= bstSortOrder.length) return;
  out.innerHTML += '<span>' + bstSortOrder[bstSortIndex++] + '</span>';
}
function autoBstSort(){
  resetBstSort();
  var timer = setInterval(function(){
    nextBstSort();
    if(bstSortIndex >= bstSortOrder.length) clearInterval(timer);
  }, 450);
}

// 主題 9 BST 搜尋互動：使用 s 開頭的節點 id。
function resetSearchNodes(){
  document.querySelectorAll('[id^="s"]').forEach(function(n){ n.classList.remove('hit','path','active'); });
  var log = document.getElementById('searchLog');
  if(log) log.textContent = '選擇一個目標值開始搜尋。';
}
function demoSearch(target){
  resetSearchNodes();
  var paths = {8:[7,14,10,8], 1:[7,3,2,1], 15:[7,14,16]};
  var path = paths[target] || [7];
  var log = document.getElementById('searchLog');
  var i = 0;
  var timer = setInterval(function(){
    if(i >= path.length){
      if(log) log.textContent = '搜尋 ' + target + '：路徑 ' + path.join(' → ') + (target === 15 ? '，下一步是空節點，所以 NOT FOUND。' : '，FOUND。');
      clearInterval(timer);
      return;
    }
    var el = document.getElementById('s' + path[i]);
    if(el) el.classList.add(i === path.length - 1 && target !== 15 ? 'hit' : 'path');
    i++;
  }, 500);
}

// Heap 陣列互動：逐步顯示插入與刪除造成的陣列變化。
var heapStates = [
  {a:[16,14,10,8,7,3,9,1,4,2], t:'建立 Max Heap 後，最大值 16 在 index 1，也就是 root。'},
  {a:[20,16,10,8,14,3,9,1,4,2,7], t:'插入 20：先放最後，再 bubble up 到 root。'},
  {a:[16,14,10,8,7,3,9,1,4,2], t:'刪除最大值：移除 root，再把最後一個節點補到 root。'},
  {a:[14,8,10,4,7,3,9,1,2], t:'Trickle down：和較大的 child 交換，恢復 Max Heap Property。'}
];
var heapStep = 0;
function showHeap(){
  var box = document.getElementById('heapArray');
  var text = document.getElementById('heapText');
  if(!box) return;
  var st = heapStates[heapStep];
  box.innerHTML = st.a.map(function(v, i){ return '<span class="insert-item">' + (i + 1) + ':' + v + '</span>'; }).join('');
  if(text) text.textContent = st.t;
}
function nextHeap(){ heapStep = (heapStep + 1) % heapStates.length; showHeap(); }
function prevHeap(){ heapStep = (heapStep - 1 + heapStates.length) % heapStates.length; showHeap(); }

// 複製程式碼：支援 textarea、pre > code，並優先使用 Clipboard API。
function copyCode(id){
  var el = document.getElementById(id);
  if(!el) return;
  var text = ('value' in el) ? el.value : el.textContent;
  if(navigator.clipboard && navigator.clipboard.writeText){
    navigator.clipboard.writeText(text).then(function(){ alert('程式碼已複製'); }).catch(function(){ fallbackCopy(text); });
  }else{
    fallbackCopy(text);
  }
}
function fallbackCopy(text){
  var temp = document.createElement('textarea');
  temp.value = text;
  document.body.appendChild(temp);
  temp.select();
  document.execCommand('copy');
  document.body.removeChild(temp);
  alert('程式碼已複製');
}

// 下載程式碼：把目前 textarea 或 code 內容存成 .c 檔。
function downloadCode(id, filename){
  var el = document.getElementById(id);
  if(!el) return;
  var text = ('value' in el) ? el.value : el.textContent;
  var blob = new Blob([text], {type:'text/plain;charset=utf-8'});
  var a = document.createElement('a');
  a.href = URL.createObjectURL(blob);
  a.download = filename || 'code.c';
  a.click();
  URL.revokeObjectURL(a.href);
}

// 頁面載入後，自動初始化流程圖、表示法切換、刪除案例與 Heap 示範。
document.addEventListener('DOMContentLoaded', function(){
  document.querySelectorAll('[data-flow]').forEach(function(b){ initFlow(b.dataset.flow); });
  if(document.getElementById('arrayPanel')) showRep('arrayPanel');
  if(document.getElementById('delcase1')) showDeleteCase(1);
  if(document.getElementById('heapArray')) showHeap();
  if(document.getElementById('buildLog')) resetBuild();
});
