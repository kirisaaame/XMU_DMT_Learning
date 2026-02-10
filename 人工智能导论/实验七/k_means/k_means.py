import numpy as np

class KMeans:
    def __init__(self,data,num_clusters):
        self.data = data
        self.num_clusters = num_clusters
        
    def train(self,max_iterations):
        #1.先随机选择K个中心点
        centroids = KMeans.centroids_init(self.data,self.num_clusters)
        #2.开始训练
        num_examples = self.data.shape[0]
        closest_centroids_ids = np.empty((num_examples,1))
        for _ in range(max_iterations):
            #3得到当前每一个样本点到K个中心点的距离，找到最近的
            closest_centroids_ids = KMeans.centroids_find_closest(self.data,centroids)
            #4.进行中心点位置更新
            centroids = KMeans.centroids_compute(self.data,closest_centroids_ids,self.num_clusters)
        return centroids, closest_centroids_ids
                
    @staticmethod    
    def centroids_init(data,num_clusters):
        num_examples = data.shape[0]
        random_ids = np.random.permutation(num_examples)
        centroids = data[random_ids[:num_clusters],:]
        return centroids
    @staticmethod 
    def centroids_find_closest(data,centroids):
        num_examples = data.shape[0]
        num_centroids = centroids.shape[0]
        closest_centroids_ids = np.zeros((num_examples,1))
        for example_index in range(num_examples):
            distance = np.zeros((num_centroids,1))
            for centroid_index in range(num_centroids):
                distance_diff = data[example_index,:] - centroids[centroid_index,:]
                distance[centroid_index] = np.sum(distance_diff**2)
            closest_centroids_ids[example_index] = np.argmin(distance)
        return closest_centroids_ids
    @staticmethod
    def centroids_compute(data,closest_centroids_ids,num_clusters):
        num_features = data.shape[1]
        centroids = np.zeros((num_clusters,num_features))
        for centroid_id in range(num_clusters):
            closest_ids = closest_centroids_ids == centroid_id
            centroids[centroid_id] = np.mean(data[closest_ids.flatten(),:],axis=0)
        return centroids
                
            
        
        
        