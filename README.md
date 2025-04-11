
<style>
.ribbon {
     width: 382px;
     position: absolute;
     left: 50%;
     top: 20px;
     margin-left: -191px;
     text-align: center;
     font-size: 15px !important;
     background: #00529B;
     background: linear-gradient(to bottom, #00529B, #003D73);
     box-shadow: rgba(0,0,0,0.3) 0 1px 1px;
     font-family: 'Helvetica Neue',Helvetica, sans-serif;
}

.ribbon p {
     font-size: 25px !important;
     color: #FB6502;
     text-shadow: #C7742C 0 1px 0;
     margin: 0px;
     padding: 17px 10px;
}

.ribbon:before, .ribbon:after {
     content: '';
     position: absolute;
     display: block;
     bottom: -1em;
     border: 1.5em solid #003A6E;
     z-index: -1;
}

.ribbon:before {
     left: -2em;
     border-right-width: 1.5em;
     border-left-color: transparent;
     box-shadow: rgba(0,0,0,0.4) 1px 1px 1px;
}

.ribbon:after {
     right: -2em;
     border-left-width: 1.5em;
     border-right-color: transparent;
     box-shadow: rgba(0,0,0,0.4) -1px 1px 1px;
}

.ribbon .ribbon-content:before, .ribbon .ribbon-content:after {
     border-color: #00529B transparent transparent transparent;
     position: absolute;
     display: block;
     border-style: solid;
     bottom: -1em;
     content: '';
}

.ribbon .ribbon-content:before {
     left: 0;
     border-width: 1em 0 0 1em;
}

.ribbon .ribbon-content:after {
     right: 0;
     border-width: 1em 1em 0 0;
}

.ribbon-stitches-top {
     margin-top:2px;
     border-top: 1px dashed rgba(0, 0, 0, 0.2);
     box-shadow: 0px 0px 2px rgba(255, 255, 255, 0.5);
}

.ribbon-stitches-bottom {
     margin-bottom:2px;
     border-top: 1px dashed rgba(0, 0, 0, 0.2);
     box-shadow: 0px 0px 2px rgba(255, 255, 255, 0.3);
}

</style>
<div class="ribbon">
    <div class="ribbon-stitches-top"></div>
    <div class="ribbon-content">
        <p>
            <b>
                General Nutritional Biases
            </b>
        </p>
    </div>
    <div class="ribbon-stitches-bottom"></div>
</div>
<div style="height:120px;"></div>


**Team Name**: Fluffy Llama\
**Team Members**: Adan Alter, Corban Pendrak, Timmy Loos

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">What problem are we trying to solve?</h2>
Create an easy method to search the U.S. Department of Health & Human Services Nutritional Dataset by relevant divisions.

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Why is this a problem?</h2>
This dataset is important for understanding the general understanding of nutrition across the United States, but without clear divisions, it is unintuitive to understand.

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">When do we know that we have solved the problem?</h2>
A UI should be created that allows for a seamless display of the dataset for simple analysis.

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Data</h2>
We use the U.S. Department of Health & Human Services Nutritional Dataset.


<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);"> Tools </h2>

- C++20
- SFML

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);height:1em;">Visuals<h2>

<img style="border-radius:10px; box-shadow:10px 20px 5px orange, -20px -10px 5px blue; padding:20px; background-color:white; " src="./Docs/COP3530-Project3-Wireframe.png"/>


<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Strategy</h2>
Preliminary algorithms or data structures we may want to implement and how we represent the data.
- Concurrent vs nonconcerrent
- Merge vs quick vs heap sort vs sleep sort
- Load data using selected algorithm into objects and sort by question and state

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Distribution of Responsibility and Roles</h2>
- Design program flow: **All**
- Design abstract base class: **Corban**
- Create main method: **All**
- Create merge sort: **Adan**
- Create quick sort: **Corban**
- Create heap sort: **Timmy**
- Create sleep sort: **Corban**
- Create UI: **All**
- Connect UI to methods: **All**

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Tasks</h2>
- [x] Create GitHub repository
- [x] Document repository
- [ ] 
