<?php

/**
 * @file
 * Template file for js_example module.
 */
?>
<script type="text/javascript">
 var params = {
        charts:{chart : encodeURIComponent('[{selector: "#graphme", type: "line", container : "#graphme-container" }]')}
      };
      PE.progress(params);
</script>
<div class="demo">
<h2><?php print $title; ?></h2>
  <table id="graphme">
			<caption>2009 Individual Sales by Category</caption>
			<thead>
				<tr>
					<td></td>
					<th scope="col">food</th>
					<th scope="col">auto</th>
					<th scope="col">household</th>
					<th scope="col">furniture</th>
					<th scope="col">kitchen</th>
					<th scope="col">bath</th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<th scope="row">Mary</th>
					<td>300</td>
					<td>160</td>
					<td>40</td>
					<td>120</td>
					<td>100</td>
					<td>70</td>
				</tr>
				<tr>
					<th scope="row">Tom</th>
					<td>3</td>
					<td>40</td>
					<td>30</td>
					<td>45</td>
					<td>35</td>
					<td>49</td>
				</tr>
				<tr>
					<th scope="row">Brad</th>
					<td>10</td>
					<td>180</td>
					<td>10</td>
					<td>85</td>
					<td>70</td>
					<td>79</td>
				</tr>
				<tr>
					<th scope="row">Kate</th>
					<td>40</td>
					<td>80</td>
					<td>90</td>
					<td>25</td>
					<td>15</td>
					<td>119</td>
				</tr>		
			</tbody>
		</table>
		
		<div id="graphme-container"></div>
</div><!-- End demo -->
