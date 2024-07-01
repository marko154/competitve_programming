// import cheerio from "cheerio";
import { spawn } from "child_process";

const topics = [
  "2-sat",
  "ad-hoc",
  "advanced",
  "bigint",
  "binary",
  "bipartite-matching",
  "bit-manipulation",
  "brute-force",
  "data-structure",
  "dp",
  "easy",
  "eulerian-path",
  "flow",
  "geometry",
  "graphs",
  "greedy",
  "implementation",
  "interactive",
  "lca",
  "linear-system",
  "linked-list",
  "meet-in-the-middle",
  "number-theory",
  "persistent",
  "prefix-sum",
  "probability",
  "scc",
  "shortest-path",
  "simple-math",
  "sort",
  "spanning-tree",
  "sqrt-decomposition",
  "steiner-tree",
  "strings",
  "suffix",
  "topological-sort",
  "union-find",
  "work-in-progress",
];
const url = "https://putka-upm.acm.si/tasks/tags/";

import path from "path";
import fs from "fs";

const freqs = [];
for (const topic of topics) {
  const tp = path.join(process.cwd(), "pages", topic + ".txt");
  const content = fs.readFileSync(tp).toString();
  let count = content.match(/V sistemu (je|sta|so) (\d+) naloga?/)?.[2];
  freqs.push([topic, parseInt(count)]);

  const command = `curl 'https://putka-upm.acm.si/tasks/tags/${topic}/' \
  -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7' \
  -H 'Accept-Language: en-US,en;q=0.9' \
  -H 'Cache-Control: max-age=0' \
  -H 'Connection: keep-alive' \
  -H 'Cookie: lang=sl; csrftoken=7Ux2qO1GOBL5pLujF7fnRHXDQeLhXHMY; sessionid=stqs8fdg5lbyon2293x2ehz1mws324hc' \
  -H 'Referer: https://putka-upm.acm.si/tasks/tags/' \
  -H 'Sec-Fetch-Dest: document' \
  -H 'Sec-Fetch-Mode: navigate' \
  -H 'Sec-Fetch-Site: same-origin' \
  -H 'Sec-Fetch-User: ?1' \
  -H 'Upgrade-Insecure-Requests: 1' \
  -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36' \
  -H 'sec-ch-ua: "Not(A:Brand";v="24", "Chromium";v="122"' \
  -H 'sec-ch-ua-mobile: ?0' \
-H 'sec-ch-ua-platform: "Linux"' > pages/${topic}.txt`;

  // const process = spawn(command, { shell: true });
  // process.stdout.on("data", (data) => {
  //   const content = String(data);
  //   console.log(content);
  // });
  // processes.push(process);
}

// const $ = cheerio.load('<h2 class="title">Hello world</h2>');
// console.log(topics);
freqs.sort((a, b) => a[1] - b[1]);
console.log(freqs);
