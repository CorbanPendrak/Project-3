<div class="ribbon" style="
     width: 382px;position: absolute;left: 50%;top: 20px;margin-left: -191px;text-align: center;font-size: 15px !important;background: #00529B;background: linear-gradient(to bottom, #00529B, #003D73);box-shadow: rgba(0,0,0,0.3) 0 1px 1px;font-family: 'Helvetica Neue',Helvetica, sans-serif;border-radius:10px">
    <div class="ribbon-stitches-top" style="
     margin-top:2px;border-top: 1px dashed rgba(0, 0, 0, 0.2);box-shadow: 0px 0px 2px rgba(255, 255, 255, 0.5);"></div>
    <div class="ribbon-content">
        <h1 style="padding: 0;margin: 0;margin-top: 10px;
     font-size: 25px !important;color: #FB6502;text-shadow: #C7742C 0 1px 0;margin: 0px;padding: 17px 10px;">
            <b>
                General Nutritional Biases
            </b>
        </h1>
    </div>
    <div class="ribbon-stitches-bottom" style="margin-bottom:2px;border-top: 1px dashed rgba(0, 0, 0, 0.2);box-shadow: 0px 0px 2px rgba(255, 255, 255, 0.3);"></div>
</div>
<div style="height:100px;"></div>


**Team Name**: Fluffy Llama\
**Team Members**: Adan Alter, Corban Pendrak, Timmy Loos

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">What problem are we trying to solve?</h2>
Create an easy method to search the U.S. Department of Health & Human Services Nutritional Dataset by relevant divisions.

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Why is this a problem?</h2>
This dataset is important for understanding the general understanding of nutrition across the United States, but without clear divisions, it is unintuitive to understand.

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">When do we know that we have solved the problem?</h2>
A UI should be created that allows for a seamless display of the dataset for simple analysis.

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">What are we analyzing?</h2>
We use the U.S. Department of Health & Human Services Nutritional Dataset.


<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">What are we using?</h2>

- Catch
- C++20
- SFML

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);height:1em;">What should it look like?<h2>

<img style="border-radius:10px; box-shadow:10px 20px 5px orange, -20px -10px 5px blue; padding:20px; background-color:white; " src="./Docs/COP3530-Project3-Wireframe.png"/>


<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">How are we going to do this?</h2>
Preliminary algorithms or data structures we may want to implement and how we represent the data.
- Concurrent vs nonconcerrent
- Merge vs quick vs heap sort vs sleep sort
- Load data using selected algorithm into objects and sort by question and state

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Who is going to do what?</h2>

- Design program flow: **All**
- Design abstract base class: **Corban**
- Create main method: **All**
- Create merge sort: **Adan**
- Create quick sort: **Corban**
- Create heap sort: **Timmy**
- Create sleep sort: **Corban**
- Create UI: **All**
- Connect UI to methods: **All**

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Code Flow</h2>

Here are the steps for programming. Please follow them to ensure consistent code across the repository.
1. Check responsibilities for problem to solve
2. Track steps with Tasks below
3. Write your code with documentation
   1. Use git branches to separate and test algorithms
   2. Document function/class **purpose**, **input**, and **output**
   3. Document **confusing lines of code**
   4. Commit frequently at breaks to save code
   5. Use "If added, this commit will {Your commit}" format
4. Test your code
   1. Write a Catch test in `/tests`
   2. Check code coverage
5. Merge your code into the `master` branch

<h2 style="text-shadow: 5px 5px 3px rgba(251, 101, 2, 0.8);">Tasks</h2>

- [x] Create GitHub repository @CorbanPendrak
  - [x] Document repository @CorbanPendrak
  - [x] Style repository @CorbanPendrak
  - [x] Describe code flow
- [ ] Setup Dependencies
  - [x] Setup SFML @CorbanPendrak
  - [ ] Precommit hook to reformat code
  - [ ] Setup Catch
  - [ ] Create SFML Catch test
  - [ ] Setup code coverage
- [ ] Program flow design
