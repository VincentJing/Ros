# git 使用过程
#### git原理
>Git更像是把变化的文件作快照后，记录在一个微型的文件系统中。每次提交更新时，它会纵览一遍所有文件的指纹信息并对文件作一快照，然后保存一个指向这次快照的索引。为提高性能，若文件没有变化，Git不会再次保存，而只对上次保存的快照作一链接。<br>
Git三种状态：working、staging、git&nbsp;directory<br>
在working中git&nbsp;add-》staging，在使用git&nbsp;commit-》git&nbsp;directory<br>
在working中git&nbsp;clone将库中的工作重新加载下来<br>
#### git配置
>首先在你电脑中生成SSH&nbsp;key(ssh&nbsp;keygen&nbsp;-t&nbsp;ras)将公钥复制到gitlab的SSHkey中。
>>* 1Git全局变量的设置
>>>git&nbsp;config&nbsp;--global&nbsp;user.name&nbsp;"xxx"<br>
   git&nbsp;config&nbsp;--global&nbsp;user.email&nbsp;"xxx@irobsen.com"<br>
>>* 2创建一个新的库
>>>git&nbsp;clone&nbsp;SSH地址<br>
	cd&nbsp;SSH中的地址<br>
	touch&nbsp;README.md<br>
	git&nbsp;add&nbsp;README.md<br>
	git&nbsp;commit&nbsp;-m&nbsp;"add&nbsp;README"<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;master<br>
>>* 3存在的文件夹
>>>cd&nbsp;existing_folder<br>
	git&nbsp;init<br>
	git&nbsp;remote&nbsp;add&nbsp;origin&nbsp;SSH地址<br>
	git&nbsp;add&nbsp;.<br>
	git&nbsp;commit&nbsp;-m&nbsp;"Initial&nbsp;commit"<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;master<br>
>>* 存在的Git库
>>>cd&nbsp;existing_repo<br>
	git&nbsp;remote&nbsp;add&nbsp;origin&nbsp;SSH地址<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;--all<br>
	git&nbsp;push&nbsp;-u&nbsp;origin&nbsp;--tags<br>

### 常用的git命令
>>* git&nbsp;add<br>
    跟踪某一个文件夹<br>
    git&add&&文件名&
>>* git&nbsp;commit<br>
    Git&nbsp;仓库中的提交记录保存的是你的目录下所有文件的快照，就像是把整个目录复制，然后再粘贴一样，但比复制粘贴优雅许多！<br>
    Git&nbsp;希望提交记录尽可能地轻量，因此在你每次进行提交时，它并不会盲目地复制整个目录。条件允许的情况下，它会将当前版本与仓库中的上一个版本进行对比，并把所有的差异打包到一起作为一个提交记录。<br>
    Git&nbsp;还保存了提交的历史记录。这也是为什么大多数提交记录的上面都有父节点的原因。对于项目组的成员来说，维护提交历史对大家都有好处。<br>
    现在你可以把提交记录看作是项目的快照。提交记录非常轻量，可以快速地在这些提交记录之间切换！<br>
    git&commit&-m&"修改内容描述"<br>
>>* git&nbsp;branch<br>
    Git&nbsp;的分支也非常轻量。它们只是简单地指向某个提交纪录——仅此而已。所以许多Git爱好者传颂：早建分支！多用分支！<br>
    这是因为即使创建再多分的支也不会造成储存或内存上的开销，并且按逻辑分解工作到不同的分支要比维护那些特别臃肿的分支简单多了。<br>
    在将分支和提交记录结合起来后，我们会看到两者如何协作。现在只要记住使用分支其实就相当于在说：“我想基于这个提交以及它所有的父提交进行新的工作。”<br>
    $git&branch&//列出本地分支<br>
    $git&branch&-r&//列出远程分支<br>
    $git&branch&-a&//列出所有分支<br>
    $git&branch&分支名&//创建分支<br>
    $git&branch&-m&oldbranchname&newbranchname&//给分支重新命名<br>
    $git&branch&-d&branchname&//删除本地分支<br>
    $git&branch&-d&-r&branchname&//删除远程分支<br>
>>* git&nbsp;merge<br>
    太好了!我们已经知道如何提交以及如何使用分支了。接下来咱们看看如何将两个分支合并到一起。就是说我们新建一个分支，在其上开发某个新功能，开发完成后再合并回主线。<br>
    咱们先来看一下第一种方法——git&nbsp;merge。在Git中合并两个分支时会产生一个特殊的提交记录，它有两个父节点。翻译成自然语言相当于：“我要把这两个父节点本身及它们所有的祖先都包含进来。”<br>
    $git&commit&branchname&//将该分支和当前分支合并，产生一个新的节点为前两个节点的子节点<br>   
>>* git&nbsp;rebase<br>
    第二种合并分支的方法是git&nbsp;rebase。Rebase&nbsp;实际上就是取出一系列的提交记录，“复制”它们，然后在另外一个地方逐个的放下去。<br>
    Rebase的优势就是可以创造更线性的提交历史，这听上去有些难以理解。如果只允许使用Rebase的话，代码库的提交历史将会变得异常清晰。<br>
    $git&rebase&branchname&//将该分支和当前分支合并，且该分支为当前分支子分子<br>
>>* git&nbsp;pull(git&nbsp;fetch和git&nbsp;merge的缩写)<br>
    取回远程主机某个分支的更新，再与本地的指定分支合并。一般用于远程分支领先于本地分支<br>
    $git&pull&origin&next:master&//远程分支next和master分支合并<br>
    $git&pull&origin&next&//远程分支next和当前分支合并<br>
    当使用git&branch&--set-upstream&master&origin/next后，追踪远程分支,指定master分支追踪origin/next分支<br>
    $git&pull&origin&//将当前分支和远程next分支合并<br>
>>* 撤销git&commit<br>
    1.$git&log&//查看提交的SHA,即是commit后面的<br>
    2.$git&reset&--hard&SHA&（你想撤销的push前一个）<br>
    3.$git&reset&SHA<br>
    1,2结合撤销commit并且还撤销代码修改<br>
    1,3只是撤销commit<br>
>>* 撤销git&push<br>
    1.$git&log&//查看提交的SHA,即是commit后面的<br>
    2.$git&reset&--hard&SHA&（你想撤销的push前一个）<br>
    3.$git&push&--force&branch<br>
>>* git&nbsp;fetch<br>
>>* 分离HEAD<br>
    我们首先看一下“HEAD”。HEAD是一个对当前检出记录的符号引用——也就是指向你正在其基础上进行工作的提交记录。<br>
    HEAD总是指向当前分支上最近一次提交记录。大多数修改提交树的Git命令都是从改变HEAD的指向开始的。<br>
    HEAD通常情况下是指向分支名的（如bugFix）。在你提交时，改变了bugFix的状态，这一变化通过HEAD变得可见。<br>
>>* 相对引用~<br>
    如果你想在提交树中向上移动很多步的话，敲那么多^貌似也挺烦人的，Git当然也考虑到了这一点，于是又引入了操作符~。<br>
    该操作符后面可以跟一个数字（可选，不跟数字时与^相同，向上移动一次），指定向上移动多少次。咱们还是通过实际<br>
    我使用相对引用最多的就是移动分支。可以直接使用 -f 选项让分支指向另一个提交。例如:<br>git&nbsp;branch&nbsp;-f&nbsp;HEAD~n<br>
>>* 相对引用^<br>
    所以master^相当于“master的父节点”。
>>* 撤销变更<br>
    Git里撤销变更的方法很多。和提交一样，撤销变更由底层部分（暂存区的独立文件或者片段）和上层部分（变更到底是通过哪咱方式被撤销的）组成。我们这个应用主要关注的是后者。<br>
    主要有两种方法用来撤销变更——一是git&nbsp;reset，还有就是git&nbsp;revert。接下来咱们逐个进行讲解。<br>
    git&nbsp;reset<br>
    通过把分支记录回退几个提交记录来实现撤销改动。你可以将这想象成“改写历史”。git&nbsp;reset向上移动分支，原来指向的提交记录就跟从来没有提交过一样。<br>
    为了撤销更改并分享给别人，我们需要使用git&nbsp;revert。
>>* git&nbsp;cherry-pick<br>
    如果你想将一些提交复制到当前所在的位置（HEAD）下面的话， Cherry-pick是最直接的方式了。我个人非常喜欢cherry-pick，因为它特别简单。<br>
    交互git&nbsp;rebase<br>
    eg.git&nbsp;rebase&nbsp;-i&nbsp;HEAD~n
>>* 只取一个提交记录<br>
	git&nbsp;rebase<br>
	git&nbsp;cherry-pick<br>
>>* 提交的技巧#1<br>
    先用git&nbsp;rebase&nbsp;-i将提交重新排序，然后把我们想要修改的提交记录挪到最前<br>
    然后用commit&nbsp;--amend来进行一些小修改<br>
    接着再用git&nbsp;rebase-i来将他们调回原来的顺序<br>
    最后我们把master移到修改的最前端（用你自己喜欢的方法），就大功告成啦！<br>
    
#### 一般的工作流程
>>* 分支介绍：<br>
    master:主分支<br>
    develop:开发分支<br>
    feature:功能分支<br>
    release:发行分支<br>
    hotfix:补丁分支<br>
>>* 分阶段功能<br>
    开发新功能：<br>
    $git&nbsp;branch&nbsp;feature&nbsp;develop创建feature分支,在开发分支处<br>
    $git&nbsp;checkout&nbsp;feature切换到功能分支<br>
    功能完成后<br>
    $git&nbsp;checkout&nbsp;develop切换到开发分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;feature将功能分支合并到开发分支中<br>
    $git&nbsp;branch&nbsp;-d&nbsp;feature删除功能分支<br>
    $git&nbsp;push&nbsp;origin&nbsp;develop放入开发库中<br>
>>* 新版本集成、准备发行<br>
    $git&nbsp;branch&nbsp;release1.2&nbsp;develop创建发行分支,在开发分支处<br>
    $git&nbsp;checkout&nbsp;release切换到发行分支<br>
    $./bump-version.sh&nbsp;1.2(修改元数据文件中的版本，可手动操作)<br>
    $git&nbsp;commit&nbsp;-a-m&nbsp;"Bumped&nbsp;version&nbsp;number&nbsp;to&nbsp;1.2"提交到暂存态<br>
    $git&nbsp;checkout&nbsp;master切换到主分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;release-1.2将发行分支合并到主分支<br>
    $git&nbsp;tag&nbsp;-a&nbsp;1.2在该主分支上打上标记<br>
    $git&nbsp;checkout&nbsp;develop切换到开发分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;release-1.2将发行分支合并到开发分支<br>
    $git&nbsp;branch&nbsp;-d&nbsp;release&nbsp;-1.2删除开发分支<br>
>>* 开发版本补丁
    $git&nbsp;branch&nbsp;hotfix-1.2.1&nbsp;master在master处创建补丁分支<br>
    $./bump-version.sh&nbsp;1.2.1(修改元数据文件中的版本，可手动操作)<br>
    $git&nbsp;commit&nbsp;-a-m&nbsp;"Bumped&nbsp;version&nbsp;number&nbsp;to&nbsp;1.2.1"提交到暂存态<br>
    $git&nbsp;commit&nbsp;-m&nbsp;"Fixed&nbsp;severe&nbsp;production&nbsp;problem"提交补丁 修改
    $git&nbsp;checkout&nbsp;master切换主分主<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;hotfix-1.2.1合并到主分主<br>
    $git&nbsp;tag&nbsp;-a&nbsp;1.2.1在该分支处打上标记1.2.1<br>
    $git&nbsp;checkout&nbsp;develop切换到开发分支<br>
    $git&nbsp;merge&nbsp;--no-ff&nbsp;hotfix-1.2.1将补丁分支合并到开发分支中<br>
    $git&nbsp;branch&nbsp;-d&nbsp;hotfix-1.2.1删除补丁分支<br>